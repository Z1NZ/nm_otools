/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:01:26 by srabah            #+#    #+#             */
/*   Updated: 2017/05/13 14:01:30 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

char	*ft_strstr(char *str, char *to_find)
{
	char	*tmp1;
	char	*tmp2;

	if (*to_find == 0)
		return ((char *)str);
	while (*str != 0)
	{
		tmp1 = str;
		tmp2 = to_find;
		while (*tmp1 == *tmp2 && *tmp1 != 0 && *tmp2 != 0)
		{
			tmp1++;
			tmp2++;
		}
		if (*tmp2 == 0)
			return ((char *)str);
		str++;
	}
	return (0);
}
