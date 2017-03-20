
#include "ft_nm.h"
#include <unistd.h>

static char type_nb(uint8_t i)
{
	if (i == 1)
		return ('t');
	else if (i == 3)
		return ('d');
	else if (i == 4)
		return ('b');
	else if (i == 9)
		return ('d');
	return ('s');
	// return ' ';
}

static char	get_type_64(struct nlist_64 *sym)
{
	if (sym->n_type & N_EXT)
	{
		// upeercase
		if ((sym->n_type & N_TYPE) == N_SECT)
			return (ft_toupper((type_nb(sym->n_sect))));
		if ((sym->n_type & N_TYPE) == N_UNDF)
			return (sym->n_value ? 'C' : 'U');
		if ((sym->n_type & N_TYPE) == N_ABS)
			return 'A';
		if ((sym->n_type & N_TYPE) == N_INDR)
			return 'I';
		return ' ';
	}
	else
	{
		// lowercase
		if ((sym->n_type & N_TYPE) == N_SECT)
			return (type_nb(sym->n_sect));
		if ((sym->n_type & N_TYPE) == N_UNDF)
			return 'u';
		if ((sym->n_type & N_TYPE) == N_ABS)
			return 'a';
		if ((sym->n_type & N_TYPE) == N_INDR)
			return 'i';
		return ' ';
	}
}

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
		{
			ft_putstr("N_STAB");
		}
		else if (tab[i].n_type & N_PEXT)
		{
			ft_putstr("N_PEXT");
		}
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
		sort_list(h_list);
		simple_print(h_list);
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
