/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 13:39:07 by srabah            #+#    #+#             */
/*   Updated: 2017/05/13 13:39:09 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	free_lib(t_llib *lib)
{
	t_llib *tmp;

	while (lib)
	{
		tmp = lib;
		lib = lib->next;
		free(tmp);
	}
}
