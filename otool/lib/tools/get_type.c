#include "ft_otool.h"


// #define	N_ABS	0x2		/* absolute, n_sect == NO_SECT */




char	get_type_64(struct nlist_64 *nl, t_count count)
{
	char		c;

	c = '?';
	if ((nl->n_type & N_TYPE) == N_UNDF)
	{	
		c = 'u';
		if (nl->n_value != 0)
			c = 'c';
	}
	else if ((nl->n_type & N_TYPE) == N_ABS)
		c = 'a';
	else if ((nl->n_type & N_TYPE) == N_SECT)
	{
		if (nl->n_sect == count.text)
			c = 't';
		else if (nl->n_sect == count.data)
			c = 'd';
		else if (nl->n_sect == count.bss)
			c = 'b';
		else
			c = 's';
	}
	else if ((nl->n_type & N_TYPE) == N_PBUD)
		c = 'u';
	else if ((nl->n_type & N_TYPE) == N_INDR)
		c = 'i';
	if ((nl->n_type & N_EXT) != 0 && c != '?')
		c = ft_toupper(c);
	return (c);
}

char	get_type(struct nlist *nl, t_count count)
{
	char		c;

	c = '?';
	if ((nl->n_type & N_TYPE) == N_UNDF)
	{	
		c = 'u';
		if (nl->n_value != 0)
			c = 'c';
	}
	else if ((nl->n_type & N_TYPE) == N_ABS)
		c = 'a';
	else if ((nl->n_type & N_TYPE) == N_SECT)
	{
		if (nl->n_sect == count.text)
			c = 't';
		else if (nl->n_sect == count.data)
			c = 'd';
		else if (nl->n_sect == count.bss)
			c = 'b';
		else
			c = 's';
	}
	else if ((nl->n_type & N_TYPE) == N_PBUD)
		c = 'u';
	else if ((nl->n_type & N_TYPE) == N_INDR)
		c = 'i';
	if ((nl->n_type & N_EXT) != 0 && c != '?')
		c = ft_toupper(c);
	return (c);
}
