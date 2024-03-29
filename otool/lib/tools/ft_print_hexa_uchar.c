/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_uchar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 19:36:38 by srabah            #+#    #+#             */
/*   Updated: 2017/05/20 19:36:44 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"
#include <unistd.h>

void			ft_print_hexa_uchar(unsigned char number)
{
	static char	base[] = "0123456789abcdef";
	int			current_rest;
	char		addr[2];
	int			i;

	addr[0] = '0';
	addr[1] = '0';
	current_rest = 0;
	i = 0;
	while (number)
	{
		current_rest = number % 16;
		addr[i] = base[current_rest];
		number /= 16;
		i++;
	}
	write(1, &addr[1], 1);
	write(1, &addr[0], 1);
}
