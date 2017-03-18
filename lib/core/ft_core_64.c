
#include "ft_nm.h"
#include <unistd.h>

/*
value  is  followed  by one of the following characters, representing the symbol type: 
U (unde-fined),
A (absolute),
T (text section symbol),
D (data section symbol),
B  (bss  section  symbol),
C (common  symbol), -  (for debugger symbol table entries; see -a below),
S (symbol in a section otherthan those above), or
I (indirect symbol).  If the symbol is local (non-external),the symbol
s  typeis  instead  represented  by  the corresponding lowercase letter.  A lower case u in a dynamic shared
library indicates a undefined reference to a private external in another module in the same  library.
*/
void	ft_put_out_test(unsigned long nsyms, unsigned long symoff, unsigned long stroff, char *ptr)
{
	char 							*string;
	struct nlist_64					*tab;
	unsigned long					i;

	tab = (void *)((char *)ptr + symoff);
	string = ptr + stroff;
	i = 1;
	while(i < nsyms)
	{
		pri_addr(tab[i].n_value);
		if (tab[i].n_type & N_STAB)
			ft_putstr("N_STAB   ");
		else if (tab[i].n_type & N_PEXT)
			ft_putstr("N_PEXT   ");
		else if (tab[i].n_type & N_TYPE)
		{
			if (tab[i].n_type == N_UNDF && tab[i].n_sect == NO_SECT)
				ft_putstr("N_UNDF");
			else if (tab[i].n_type == N_ABS && tab[i].n_sect == NO_SECT)
				ft_putstr("N_ABS");
			else if (tab[i].n_type == N_SECT) // type 't'
			{
				ft_putstr("SUPER === ");
				ft_putnbr(tab[i].n_sect);
				if (tab[i].n_sect == 0)
					ft_putstr("?");
				else if (tab[i].n_sect == 1)
					ft_putstr("t");
				else if (tab[i].n_sect == 2)
					ft_putstr("2");
				else if (tab[i].n_sect == 3)
					ft_putstr("3");
				else if (tab[i].n_sect == 4)
					ft_putstr("b");
				else if (tab[i].n_sect == 5)
					ft_putstr("5");
				else if (tab[i].n_sect == 6)
					ft_putstr("6");
				else if (tab[i].n_sect == 7)
					ft_putstr("7");
				else if (tab[i].n_sect == 8)
					ft_putstr("8");
				else if (tab[i].n_sect == 9)
					ft_putstr("d");
				else if (tab[i].n_sect == 10)
					ft_putstr("10");
			}

		}
		else if (tab[i].n_type & N_EXT) // TYPE U
			ft_putstr("U ");

		ft_putstr(string + tab[i].n_un.n_strx);
		ft_putstr("\n");
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
