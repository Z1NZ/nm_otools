/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 13:49:09 by srabah            #+#    #+#             */
/*   Updated: 2017/05/13 14:43:53 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_free_list(t_list *head)
{
	t_list *tmp;

	tmp = NULL;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = NULL;
		head = tmp;
	}
}

void	ft_free_list_litle(t_list *head)
{
	t_list *tmp;

	tmp = NULL;
	while (head)
	{
		tmp = head->next;
		free(head->ptr);
		head->ptr = NULL;
		free(head);
		head = NULL;
		head = tmp;
	}
}
