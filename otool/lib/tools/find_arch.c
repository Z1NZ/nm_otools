/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_arch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:17:13 by srabah            #+#    #+#             */
/*   Updated: 2017/05/22 18:17:19 by srabah           ###   ########.fr       */
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

int							find_arch(t_file_info info)
{
	struct fat_header	*p_fh;
	struct fat_arch		*p_fa;
	uint32_t			n_arch;
	struct mach_header	*p_h;

	p_fh = (void *)info.data_file;
	p_fa = (void *)(p_fh + 1);
	n_arch = endian_swap(p_fh->nfat_arch);
	while (n_arch)
	{
		info.data_file += endian_swap(p_fa->offset);
		p_h = (void *)info.data_file;
		if (p_h->cputype == CPU_TYPE_X86_64)
		{
			ft_core(info);
			return (1);
		}
		info.data_file -= endian_swap(p_fa->offset);
		++p_fa;
		--n_arch;
	}
	return (0);
}
