/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:04:16 by srabah            #+#    #+#             */
/*   Updated: 2017/05/13 14:04:18 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = (char*)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (p != NULL)
		ft_strcpy(p, s1);
	else
		ft_error_errno("ft_strdup", NULL);
	return (p);
}
