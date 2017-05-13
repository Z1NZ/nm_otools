/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:42:14 by srabah            #+#    #+#             */
/*   Updated: 2017/05/13 14:42:15 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bstr;

	bstr = b;
	while (len)
	{
		*bstr = (unsigned char)c;
		bstr++;
		len--;
	}
	return (b);
}
