/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 13:39:38 by srabah            #+#    #+#             */
/*   Updated: 2017/05/13 13:39:40 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	sort_list(t_list *ptr)
{
	t_list *tmp;

	tmp = ptr;
	while (tmp && tmp->next)
	{
		if (ft_strcmp(tmp->ptr, tmp->next->ptr) > 0)
		{
			ft_list_swap(tmp, tmp->next);
			tmp = ptr;
		}
		else if (ft_strcmp(tmp->ptr, tmp->next->ptr) == 0
				&& tmp->next->n_value < tmp->n_value)
		{
			ft_list_swap(tmp, tmp->next);
			tmp = ptr;
		}
		else
			tmp = tmp->next;
	}
}
