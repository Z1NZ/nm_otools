
#include "ft_nm.h"
#include <unistd.h>


static inline void	ft_nlist(struct symtab_command *sc, t_count count_f, t_file_info info)
{
	char 						*string;
	struct nlist				*tab;
	unsigned long				i;
	t_list						*p_list;
	t_list						*h_list;

	p_list = NULL;
	h_list = NULL;
	tab = (void *)((char *)info.data_file + sc->symoff);
	string = info.data_file + sc->stroff;
	i = 0;
	while(i < sc->nsyms)
	{
		if ((((char *)&tab[i]) - info.data_file) > info.data_stat.st_size)
		{
			ft_putstr_fd(info.filename, 2);
			ft_putstr_fd(" : The file was not recognized as a valid object file\n", 2);
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
				if ((p_list->next = ft_memalloc(sizeof(t_list))) == NULL)
					ft_error_errno("ft_memalloc", NULL);
				p_list = p_list->next;
			}
			p_list->n_value = tab[i].n_value;
			p_list->type = get_type(&tab[i], count_f);
			p_list->ptr = string + tab[i].n_un.n_strx;
		}
		i++;
	}
	if (h_list)
	{
		sort_list(h_list);
		simple_print_32(h_list);
		ft_free_list(h_list);
	}
}


static inline	void		count_flag(t_count *count, struct load_command *lc)
{
	struct segment_command 	*sc;
	struct section 			*s;
	uint32_t				j;
	uint32_t				len;

	sc = (void *)lc;
	s = (void *)(sc + 1);
	j = 0;
	len = sc->nsects;
	while (j < len)
	{
		if(!ft_strcmp(s[j].sectname, SECT_TEXT) && !ft_strcmp(s[j].segname, SEG_TEXT))
			count->text = count->k + 1;
		else if(!ft_strcmp(s[j].sectname, SECT_DATA) && !ft_strcmp(s[j].segname, SEG_DATA))
			count->data = count->k + 1;
		else if(!ft_strcmp(s[j].sectname, SECT_BSS) && !ft_strcmp(s[j].segname, SEG_DATA))
			count->bss = count->k + 1;
		j++;
		count->k++;
	}
}

void	ft_core_32(t_file_info info)
{
	struct mach_header			*p_h;
	struct load_command 		*p_lc;
	struct symtab_command		*p_sync;
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
			ft_putstr_fd(info.filename, 2);
			ft_putstr_fd(" : The file was not recognized as a valid object file\n", 2);
			return ;
		}
		if (p_lc->cmd == LC_SYMTAB)
		{
			p_sync = (void*)p_lc;
			ft_nlist((void*)p_lc, count_f, info);
			break;
		}
		if (p_lc->cmd == LC_SEGMENT)
			count_flag(&count_f, p_lc);
		p_lc = (void *)(((char *)p_lc) + p_lc->cmdsize);
		++i;
	}
}
