#include "ft_nm.h"

static char type_nb_64(uint8_t i)
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
}

static char type_nb_32(uint8_t i)
{
	if (i == 1)
		return ('t');
	else if (i == 4)
		return ('d');
	else if (i == 5 || i == 14)
		return ('b');
	return ('s');
}

char	get_type_64(struct nlist_64 *sym)
{
	if (sym->n_type & N_EXT)
	{
		// upeercase
		if ((sym->n_type & N_TYPE) == N_SECT)
			return (ft_toupper((type_nb_64(sym->n_sect))));
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
			return (type_nb_64(sym->n_sect));
		if ((sym->n_type & N_TYPE) == N_UNDF)
			return 'u';
		if ((sym->n_type & N_TYPE) == N_ABS)
			return 'a';
		if ((sym->n_type & N_TYPE) == N_INDR)
			return 'i';
		return ' ';
	}
}

char	get_type(struct nlist *sym)
{
	if (sym->n_type & N_EXT)
	{
		// upeercase
		if ((sym->n_type & N_TYPE) == N_SECT)
			return (ft_toupper((type_nb_32(sym->n_sect))));
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
			return (type_nb_32(sym->n_sect));
		if ((sym->n_type & N_TYPE) == N_UNDF)
			return 'u';
		if ((sym->n_type & N_TYPE) == N_ABS)
			return 'a';
		if ((sym->n_type & N_TYPE) == N_INDR)
			return 'i';
		return ' ';
	}
}
