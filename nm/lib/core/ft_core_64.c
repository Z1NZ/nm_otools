
#include "ft_nm.h"
#include <unistd.h>
	#include <stdio.h>

static inline void	ft_nlist_64(struct symtab_command *sc, t_count count_f, t_file_info info)
{
	char 						*string;
	struct nlist_64				*tab;
	unsigned long				i;
	t_list						*p_list;
	t_list						*h_list;

	p_list = NULL;
	h_list = NULL;
	tab = (void *)(info.data_file + sc->symoff);
	string = info.data_file + sc->stroff;
	i = 0;
	while(i < sc->nsyms)
	{
		if ((((char *)&tab[i]) - info.data_file) > info.data_stat.st_size)
		{
			ft_error_recognized(info.filename);
			return ;
		}
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
	p_list = NULL;
	if (h_list)
	{
		sort_list(h_list);
		simple_print_64(h_list);
		ft_free_list(h_list);
	}
}

static inline	void		count_flag_64(t_count *count, struct load_command *lc, t_file_info info)
{
	struct segment_command_64 	*sc;
	struct section_64 			*s;
	unsigned int j;

	sc = (void *)lc;
	s = (void*)((char *)(sc + 1));
	j = 0;
	while (j < sc->nsects)
	{
		if ((((char *)&(s[j])) - info.data_file) > info.data_stat.st_size)
		{
			ft_error_recognized(info.filename);
			return ;
		}
		if(!ft_strcmp((s[j]).sectname, SECT_TEXT) && !ft_strcmp(s[j].segname, SEG_TEXT))
			count->text = count->k + 1;
		else if(!ft_strcmp(s[j].sectname, SECT_DATA) && !ft_strcmp(s[j].segname, SEG_DATA))
			count->data = count->k + 1;
		else if(!ft_strcmp(s[j].sectname, SECT_BSS) && !ft_strcmp(s[j].segname, SEG_DATA))
			count->bss = count->k + 1;
		j++;
		count->k++;
	}
}


int	ft_core_64(t_file_info info)
{
	struct mach_header_64		*p_h;
	struct load_command 		*p_lc;
	uint32_t					i;
	t_count						count_f;

	p_h = (void *)info.data_file;
	i = 0;
	count_f.text = 0;
	count_f.data = 0;
	count_f.bss = 0;
	count_f.k = 0;
 	p_lc = (struct load_command *)(p_h + 1);
 	while(i < p_h->sizeofcmds)
 	{
 		if (((char *)(p_lc) - info.data_file) > info.data_stat.st_size)
		{
			ft_error_recognized(info.filename);
			return (1);
		}
 		if (p_lc->cmd == LC_SYMTAB)
 		{
 			ft_nlist_64((void*)p_lc,count_f, info);
			break;
 		}
		if (p_lc->cmd == LC_SEGMENT_64)
			count_flag_64(&count_f, p_lc, info);
 		p_lc = (void *)(((char *)p_lc) + p_lc->cmdsize);
 		++i;
 	}
	return(0);
}
