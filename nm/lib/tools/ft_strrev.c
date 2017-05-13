/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:01:49 by srabah            #+#    #+#             */
/*   Updated: 2017/05/13 14:01:51 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

char		*ft_strrev(char *str)
{
	char				a;
	unsigned long		f;
	unsigned long		d;

	f = (ft_strlen(str) - 1);
	d = 0;
	while (d < f && d != f)
	{
		a = str[f];
		str[f] = str[d];
		str[d] = a;
		f--;
		d++;
	}
	return (str);
}
