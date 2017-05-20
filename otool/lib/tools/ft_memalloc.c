/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 19:35:49 by srabah            #+#    #+#             */
/*   Updated: 2017/05/20 19:35:53 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*new_space;

	if (!size)
		return (NULL);
	new_space = (void*)malloc(size * sizeof(void*));
	if (!new_space)
	{
		ft_error_errno("ft_memalloc", NULL);
		exit(-1);
	}
	ft_memset((unsigned char*)new_space, 0, size);
	return (new_space);
}
