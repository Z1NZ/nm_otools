
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
	ft_putnbr(i);
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
		ft_putnbr(sym->n_type);
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
		ft_putnbr(sym->n_type);
		return ' ';
	}
}

void	ft_put_out_test(unsigned long nsyms, unsigned long symoff, unsigned long stroff, char *ptr)
{
	char 							*string;
	struct nlist_64					*tab;
	unsigned long					i;

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
			if (tab[i].n_value)
				pri_addr(tab[i].n_value);
			else
				write(1, "                ", 16);
			write(1," ", 1);
			if ((tab[i].n_type & N_TYPE) || tab[i].n_type & N_EXT)
			{
				char c = get_type_64(&tab[i]);
				write(1, &c, 1);
				write(1, " ", 1);
				ft_putstr(string + tab[i].n_un.n_strx);
				ft_putstr("\n");
			}
		}
		i++;
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
