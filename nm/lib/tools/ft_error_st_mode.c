/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_st_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:41:21 by srabah            #+#    #+#             */
/*   Updated: 2017/05/13 14:41:26 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_error_st_mode(mode_t st_mode, char *name)
{
	ft_putstr_fd(name, 2);
	if (S_ISDIR(st_mode))
		ft_putstr_fd(": Is a directory\n", 2);
}
