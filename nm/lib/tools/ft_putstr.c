/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:41:36 by srabah            #+#    #+#             */
/*   Updated: 2017/05/13 14:41:38 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"
#include <unistd.h>

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_put_2_str(char *s, char *s1)
{
	ft_putstr(s);
	ft_putstr(s1);
}
