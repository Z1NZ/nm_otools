/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 17:57:05 by srabah            #+#    #+#             */
/*   Updated: 2017/05/20 17:57:06 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"
#include <unistd.h>

t_list		*new_list(t_list *p_list, t_list **h_list)
{
	if (p_list == NULL)
	{
		if ((p_list = ft_memalloc(sizeof(t_list))) == NULL)
			ft_error_errno("ft_memalloc", NULL);
		*h_list = p_list;
	}
	else
	{
		if ((p_list->next = ft_memalloc(sizeof(t_list))) == NULL)
			ft_error_errno("ft_memalloc", NULL);
		p_list = p_list->next;
	}
	return (p_list);
}
