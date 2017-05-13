/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_recognized.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:40:56 by srabah            #+#    #+#             */
/*   Updated: 2017/05/13 14:41:02 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		ft_error_recognized(const char *ptr)
{
	ft_putstr_fd("ft_nm: ", 2);
	ft_putstr_fd(ptr, 2);
	ft_putstr_fd(ERROR, 2);
	return (1);
}
