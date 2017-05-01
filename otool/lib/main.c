/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 22:00:05 by srabah            #+#    #+#             */
/*   Updated: 2017/04/30 22:00:07 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"
#include <unistd.h>
#include <fcntl.h>

int		ft_openner(t_file_info info)
{
	int fd;
	int ret;

	ret = 1;
	if ((fd = open(info.filename, O_RDONLY)) > 0)
	{
		if (fstat(fd, &(info.data_stat)) != -1)
		{
			if (S_ISREG(info.data_stat.st_mode))
			{
				ret = ft_core_mmap(fd, info);
			}
			else
				ft_error_st_mode(info.data_stat.st_mode, info.filename);
		}
		else
			ft_error_errno("ft_openner fstat ", info.filename);
		if (close(fd) == -1)
			ft_error_errno("ft_openner close ", info.filename);
	}
	else
		ft_error_errno("ft_openner open ", info.filename);
	return (ret);
}

int		main(int argc, char *argv[])
{
	unsigned int	i;
	t_file_info		info;
	int				ret;

	ret = 1;
	i = 0;
	if (argc > 1)
		while (argv[++i])
		{
			info.filename = argv[i];
			ret = ft_openner(info);
			ft_memset(&info, '\0', sizeof(t_file_info));
		}
	else
		ft_putstr_fd("error: ft_otool: at least one file must be specified\n", 2);
	return (ret);
}
