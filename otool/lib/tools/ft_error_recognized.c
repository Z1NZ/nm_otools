/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_recognized.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 19:40:53 by srabah            #+#    #+#             */
/*   Updated: 2017/05/20 19:40:58 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

int	ft_error_recognized(const char *ptr)
{
	ft_putstr_fd("ft_otool: ", 2);
	ft_putstr_fd(ptr, 2);
	ft_putstr_fd(ERROR, 2);
	return (1);
}
