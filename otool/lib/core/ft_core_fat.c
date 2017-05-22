/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_fat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 20:07:52 by srabah            #+#    #+#             */
/*   Updated: 2017/05/20 20:07:55 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static inline unsigned int	endian_swap(unsigned int x)
{
	x = (x >> (unsigned int)24) |
		((x << (unsigned int)8) & 0x00FF0000) |
		((x >> (unsigned int)8) & 0x0000FF00) |
		(x << (unsigned int)24);
	return (x);
}

int							ft_core_fat(t_file_info info)
{
	struct fat_header	*p_fh;
	struct fat_arch		*p_fa;
	uint32_t			n_arch;
	struct mach_header	*p;

	p_fh = (void *)info.data_file;
	p_fa = (void *)(p_fh + 1);
	n_arch = p_fh->nfat_arch + 1;
	if (find_arch(info))
		return (0);
	info.fat = 1;
	while (--n_arch)
	{
		info.data_file += p_fa->offset;
		p = (void *)info.data_file;
		ft_putstr(info.filename);
		(p->magic == MH_CIGAM || p->magic == MH_CIGAM_64) ? ft_print_arch((int)
			endian_swap((uint32_t)p->cputype), (int)endian_swap((uint32_t)
				p->cpusubtype)) : ft_print_arch(p->cputype, p->cpusubtype);
		ft_core(info);
		info.data_file -= p_fa->offset;
		++p_fa;
	}
	info.fat = 0;
	return (0);
}
