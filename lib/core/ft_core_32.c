
#include "ft_nm.h"
#include <unistd.h>


static inline void	ft_nlist(unsigned long nsyms, unsigned long symoff, unsigned long stroff, char *ptr)
{
	char 						*string;
	struct nlist				*tab;
	unsigned long				i;
	t_list						*p_list;
	t_list						*h_list;

	p_list = NULL;
	h_list = NULL;
	tab = (void *)((char *)ptr + symoff);
	string = ptr + stroff;
	i = 0;
	while(i < nsyms)
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
				if ((p_list->next = ft_memalloc(sizeof(t_list))) == NULL)
					ft_error_errno("ft_memalloc", NULL);
				p_list = p_list->next;
			}
			p_list->n_value = tab[i].n_value;
			p_list->type = get_type(&tab[i]);
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

void	ft_core_32(char *ptr)
{
	struct mach_header			*p_h;
	struct load_command 		*p_lc;
	struct symtab_command		*p_sync;
	uint32_t					i;

	p_h = (void *)ptr;
	i = 0;
	p_lc = (struct load_command *)(p_h + 1);
	while(i < p_h->sizeofcmds)
	{
		if (p_lc->cmd == LC_SYMTAB)
		{
			p_sync = (void*)p_lc;
			ft_nlist(p_sync->nsyms, p_sync->symoff, p_sync->stroff, ptr);
			break;
		}
		p_lc = (void *)(((char *)p_lc) + p_lc->cmdsize);
		++i;
	}
}
