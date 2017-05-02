/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 22:38:17 by srabah            #+#    #+#             */
/*   Updated: 2017/04/30 22:38:19 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"
#define STATIC_LIB 738142165265366049

int	ft_core(t_file_info info)
{
	uint32_t	magic_number;

	magic_number = *(uint32_t *)((void *)(info.data_file));
	if (STATIC_LIB == *(uint64_t *)((void *)(info.data_file)))
		return (ft_core_static_lib(info));
	else if (magic_number == MH_MAGIC)
		return (ft_core_32(info));
	else if (magic_number == MH_CIGAM)
		return (ft_core_32_litle(info));
	else if (magic_number == MH_MAGIC_64)
		return (ft_core_64(info));
	else if (magic_number == MH_CIGAM_64)
		return (ft_core_64_litle(info));
	else if (magic_number == FAT_MAGIC)
		return (ft_core_fat(info));
	else if (magic_number == FAT_CIGAM)
		return (ft_core_fat_litle(info));
	else
	{
		if (info.filename)
			ft_error_recognized(info.filename);
		else
			ft_putstr_fd("not recognized part of fat_binary ", 2);
		return (1);
	}
}
