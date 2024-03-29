/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_fat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:24:28 by srabah            #+#    #+#             */
/*   Updated: 2017/05/15 15:24:30 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

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
	struct mach_header	*p_h;

	p_fh = (void *)info.data_file;
	p_fa = (void *)(p_fh + 1);
	n_arch = p_fh->nfat_arch;
	if (find_arch(info))
		return (0);
	while (n_arch--)
	{
		info.data_file += p_fa->offset;
		p_h = (void *)info.data_file;
		ft_put_2_str("\n", info.filename);
		if (p_h->magic == MH_CIGAM || p_h->magic == MH_CIGAM_64)
			ft_print_arch((cpu_type_t)endian_swap((unsigned int)p_h->cputype),
				(cpu_subtype_t)endian_swap((unsigned int)p_h->cpusubtype));
		else
			ft_print_arch(p_h->cputype, p_h->cpusubtype);
		ft_core(info);
		info.data_file -= p_fa->offset;
		++p_fa;
	}
	return (0);
}
