/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_sect64.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:14:55 by srabah            #+#    #+#             */
/*   Updated: 2017/05/22 18:14:57 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void			hexa_sect64(char *ptr, uint64_t i)
{
	ft_print_hexa_uchar((unsigned char)ptr[i]);
	ft_print_hexa_uchar((unsigned char)ptr[i + 1]);
	ft_print_hexa_uchar((unsigned char)ptr[i + 2]);
	ft_print_hexa_uchar((unsigned char)ptr[i + 3]);
	ft_putstr(" ");
}
