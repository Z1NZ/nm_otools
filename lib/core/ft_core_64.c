
#include "ft_nm.h"
#include <unistd.h>
	#include <stdio.h>

static inline void	ft_nlist_64(struct symtab_command *sc, char *ptr, t_count count_f)
{
	char 						*string;
	struct nlist_64				*tab;
	unsigned long				i;
	t_list						*p_list;
	t_list						*h_list;

	p_list = NULL;
	h_list = NULL;
	tab = (void *)((char *)ptr + sc->symoff);
	string = ptr + sc->stroff;
	i = 0;
	while(i < sc->nsyms)
	{
		if (tab[i].n_type & N_STAB)
			;
		else if ((tab[i].n_type & N_TYPE) || tab[i].n_type & N_EXT)
		{
			if (p_list == NULL)
			{
				if ((p_list = ft_memalloc(sizeof(t_list))) == NULL)
					ft_error_errno("ft_memalloc", NULL);
				h_list = p_list;
			}
			else
			{	
				if ((p_list->next = ft_memalloc(sizeof(t_list)) )== NULL)
					ft_error_errno("ft_memalloc", NULL);
				p_list = p_list->next;
			}
			p_list->n_value = tab[i].n_value;
			p_list->type = get_type_64(&tab[i], count_f);
			p_list->ptr = string + tab[i].n_un.n_strx;
		}
		i++;
	}
	if (h_list)
	{
		sort_list(h_list);
		simple_print_64(h_list);
		ft_free_list(h_list);
	}
}

static inline	void		count_flag_64(t_count count, struct load_command *lc)
{
	struct segment_command_64 	*sc;
	struct section_64 			*s;
	unsigned int j;

	sc = (void *)lc;
	s = (void*)((char *)(sc + 1));
	j = 0;
	while (j < sc->nsects)
	{
		if(!ft_strcmp((s[j]).sectname, SECT_TEXT) && !ft_strcmp(s[j].segname, SEG_TEXT))
			count.text = count.k + 1;
		else if(!ft_strcmp(s[j].sectname, SECT_DATA) && !ft_strcmp(s[j].segname, SEG_DATA))
			count.data = count.k + 1;
		else if(!ft_strcmp(s[j].sectname, SECT_BSS) && !ft_strcmp(s[j].segname, SEG_DATA))
			count.bss = count.k + 1;
		j++;
		count.k++;
	}
}


void	ft_core_64(char *ptr)
{
	struct mach_header_64		*p_h;
	struct load_command 		*p_lc;
	uint32_t					i;
	t_count						count_f;

	p_h = (void *)ptr;
	i = 0;
	count_f.text = 0;
	count_f.data = 0;
	count_f.bss = 0;
	count_f.k = 0;
 	p_lc = (struct load_command *)(p_h + 1);
 	while(i < p_h->sizeofcmds)
 	{
		if (p_lc->cmd == LC_SEGMENT_64)
			count_flag_64(count_f, p_lc);
 		if (p_lc->cmd == LC_SYMTAB)
 		{
 			ft_nlist_64((void*)p_lc, ptr, count_f);
			break;
 		}
 		p_lc = (void *)(((char *)p_lc) + p_lc->cmdsize);
 		++i;
 	}
}
