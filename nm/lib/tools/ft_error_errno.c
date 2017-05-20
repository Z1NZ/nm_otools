/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_errno.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:44:49 by srabah            #+#    #+#             */
/*   Updated: 2017/05/13 14:44:52 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"
#include <errno.h>
#include <stdio.h>

void	*ft_error_errno(char *ptr, char *name)
{
	ft_putstr_fd(ptr, 2);
	ft_putstr_fd(sys_errlist[errno], 2);
	ft_putstr_fd(" ", 2);
	if (name)
		ft_putstr_fd(name, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}
