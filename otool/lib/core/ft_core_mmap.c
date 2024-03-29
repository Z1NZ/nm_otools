/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_mmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 20:05:50 by srabah            #+#    #+#             */
/*   Updated: 2017/05/20 20:05:51 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"
#include <sys/mman.h>

int		ft_core_mmap(int fd, t_file_info info)
{
	int ret;

	ret = 1;
	if ((info.data_file = mmap(0, (size_t)(info.data_stat.st_size),
			PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		ft_error_errno("ft_core mmap", NULL);
		exit(-1);
	}
	ret = ft_core(info);
	if (munmap(info.data_file, (size_t)(info.data_stat.st_size)) == -1)
	{
		ft_error_errno("ft_core munmap", NULL);
		exit(-1);
	}
	return (ret);
}
