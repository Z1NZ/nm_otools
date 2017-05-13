/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 13:46:51 by srabah            #+#    #+#             */
/*   Updated: 2017/05/13 13:46:53 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static inline char	flag_type(struct nlist_64 *nl, t_count count)
{
	if (nl->n_sect == count.text)
		return ('t');
	else if (nl->n_sect == count.data)
		return ('d');
	else if (nl->n_sect == count.bss)
		return ('b');
	else
		return ('s');
}

char				get_type_64(struct nlist_64 *nl, t_count count)
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
		c = flag_type(nl, count);
	else if ((nl->n_type & N_TYPE) == N_PBUD)
		c = 'u';
	else if ((nl->n_type & N_TYPE) == N_INDR)
		c = 'i';
	if ((nl->n_type & N_EXT) != 0 && c != '?')
		c = ft_toupper(c);
	return (c);
}

char				get_type(struct nlist *nl, t_count count)
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
		c = flag_type(nl, count);
	else if ((nl->n_type & N_TYPE) == N_PBUD)
		c = 'u';
	else if ((nl->n_type & N_TYPE) == N_INDR)
		c = 'i';
	if ((nl->n_type & N_EXT) != 0 && c != '?')
		c = ft_toupper(c);
	return (c);
}
