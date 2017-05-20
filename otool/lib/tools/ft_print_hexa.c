/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 19:34:42 by srabah            #+#    #+#             */
/*   Updated: 2017/05/20 19:34:44 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"
#include <unistd.h>

void			ft_print_hexa_32(unsigned long number)
{
	static char	base[] = "0123456789abcdef";
	int			current_rest;
	char		addr[9];
	int			i;

	current_rest = 0;
	i = 0;
	while (number)
	{
		current_rest = number % 16;
		addr[i] = base[current_rest];
		number /= 16;
		i++;
	}
	while (i < 8)
	{
		addr[i] = '0';
		i++;
	}
	while (--i > -1)
		write(1, &addr[i], 1);
}

void			ft_print_hexa_64(unsigned long long number)
{
	static char	base[] = "0123456789abcdef";
	int			current_rest;
	char		addr[17];
	int			i;

	current_rest = 0;
	i = 0;
	while (number)
	{
		current_rest = number % 16;
		addr[i] = base[current_rest];
		number /= 16;
		i++;
	}
	while (i < 16)
	{
		addr[i] = '0';
		i++;
	}
	while (--i > -1)
		write(1, &addr[i], 1);
}
