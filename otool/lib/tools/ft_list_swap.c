/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 19:41:59 by srabah            #+#    #+#             */
/*   Updated: 2017/05/20 19:42:05 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void	ft_list_swap(t_list *a, t_list *b)
{
	t_list c;

	c.ptr = a->ptr;
	c.type = a->type;
	c.n_value = a->n_value;
	a->ptr = b->ptr;
	a->type = b->type;
	a->n_value = b->n_value;
	b->ptr = c.ptr;
	b->type = c.type;
	b->n_value = c.n_value;
}
