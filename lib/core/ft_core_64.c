
#include "ft_nm.h"
#include <unistd.h>

void	ft_put_out_test(unsigned long nsyms, unsigned long symoff, unsigned long stroff, char *ptr)
{
	char 						*string;
	struct nlist_64				*tab;
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
				p_list = ft_memalloc(sizeof(t_list));
				h_list = p_list;
			}
			else
			{	
				p_list->next = ft_memalloc(sizeof(t_list));
				p_list = p_list->next;
			}
			p_list->n_value = tab[i].n_value;
			p_list->type = get_type_64(&tab[i]);
			p_list->ptr = string + tab[i].n_un.n_strx;
		}
		i++;
	}
	if (h_list)
	{
		sort_list(h_list);
		simple_print_64(h_list);
	}
}

void	ft_core_64(char *ptr)
{
	struct mach_header_64		*p_h;
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
 			ft_put_out_test(p_sync->nsyms, p_sync->symoff, p_sync->stroff, ptr);
 			break;
 		}
 		p_lc = (void *)(((char *)p_lc) + p_lc->cmdsize);
 		++i;
 	}
}
