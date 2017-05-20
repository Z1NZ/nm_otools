/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_lib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 19:27:42 by srabah            #+#    #+#             */
/*   Updated: 2017/05/20 19:27:44 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static void	ft_lib_swap(t_llib *a, t_llib *b)
{
	char			*ptr;
	unsigned long	offset;

	ptr = a->ptr;
	offset = a->offset;
	a->ptr = b->ptr;
	a->offset = b->offset;
	b->ptr = ptr;
	b->offset = offset;
}

void		ft_sort_lib(t_llib *lib)
{
	t_llib *tmp;

	tmp = lib;
	while (tmp && tmp->next)
	{
		if (tmp->offset > tmp->next->offset)
		{
			ft_lib_swap(tmp, tmp->next);
			tmp = lib;
		}
		else
			tmp = tmp->next;
	}
}
