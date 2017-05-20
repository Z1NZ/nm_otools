/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_errno.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 19:43:26 by srabah            #+#    #+#             */
/*   Updated: 2017/05/20 19:43:28 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"
#include <errno.h>
#include <stdio.h>

void	ft_error_errno(char *ptr, char *name)
{
	ft_putstr_fd(ptr, 2);
	ft_putstr_fd(sys_errlist[errno], 2);
	ft_putstr_fd(" ", 2);
	if (name)
		ft_putstr_fd(name, 2);
	ft_putstr_fd("\n", 2);
}
