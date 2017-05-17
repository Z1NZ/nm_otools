/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:39:07 by srabah            #+#    #+#             */
/*   Updated: 2017/05/17 13:39:15 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void		list_display(t_list *h_list)
{
	if (h_list)
	{
		sort_list(h_list);
		simple_print_32(h_list);
		ft_free_list(h_list);
	}
}

void		list_display_64(t_list *h_list)
{
	if (h_list)
	{
		sort_list(h_list);
		simple_print_64(h_list);
		ft_free_list(h_list);
	}
}
