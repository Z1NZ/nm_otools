/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_st_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 19:43:14 by srabah            #+#    #+#             */
/*   Updated: 2017/05/20 19:43:16 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void	ft_error_st_mode(mode_t st_mode, char *name)
{
	ft_putstr_fd(name, 2);
	if (S_ISDIR(st_mode))
		ft_putstr_fd(": Is a directory\n", 2);
}
