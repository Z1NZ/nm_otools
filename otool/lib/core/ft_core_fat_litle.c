/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_fat_litle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 19:57:57 by srabah            #+#    #+#             */
/*   Updated: 2017/05/20 19:57:59 by srabah           ###   ########.fr       */
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

void						ft_print_sub_arm(cpu_subtype_t sub)
{
	if (sub == CPU_SUBTYPE_ARM_V7)
		ft_putstr(" (architecture armv7):\n");
	else if (sub == CPU_SUBTYPE_ARM_V7S)
		ft_putstr(" (architecture armv7s):\n");
	else
		ft_putstr(" (architecture armv):\n");
}

void						ft_print_sub_ppc(cpu_subtype_t sub)
{
	if (sub == CPU_SUBTYPE_POWERPC_ALL)
		ft_putstr(" (architecture ppc):\n");
	else
		ft_putstr(":\n");
}

void						ft_print_arch(cpu_type_t type, cpu_subtype_t sub)
{
	if (type == CPU_TYPE_ANY)
		ft_putstr(" (architecture any):");
	else if (type == CPU_TYPE_VAX)
		ft_putstr(" (architecture vax):\n");
	else if (type == CPU_TYPE_MC680x0)
		ft_putstr(" (architecture mc680x0):\n");
	else if (type == CPU_TYPE_I386)
		ft_putstr(" (architecture i386):\n");
	else if (type == CPU_TYPE_MC98000)
		ft_putstr(" (architecture mc98000):");
	else if (type == CPU_TYPE_HPPA)
		ft_putstr(" (architecture hppa):\n");
	else if (type == CPU_TYPE_ARM)
		ft_print_sub_arm(sub);
	else if (type == CPU_TYPE_ARM64)
		ft_putstr(" (architecture arm64):\n");
	else if (type == CPU_TYPE_MC88000)
		ft_putstr(" (architecture mc88000):\n");
	else if (type == CPU_TYPE_SPARC)
		ft_putstr(" (architecture sparc):\n");
	else if (type == CPU_TYPE_POWERPC)
		ft_print_sub_ppc(sub);
	else if (type == CPU_TYPE_POWERPC64)
		ft_putstr(" (architecture powerpc64):\n");
}

int							ft_core_fat_litle(t_file_info info)
{
	struct fat_header	*p_fh;
	struct fat_arch		*p_fa;
	uint32_t			n_arch;
	struct mach_header	*p;

	p_fh = (void *)info.data_file;
	p_fa = (void *)(p_fh + 1);
	n_arch = endian_swap(p_fh->nfat_arch) + 1;
	if (find_arch(info))
		return (0);
	info.fat = 1;
	while (--n_arch)
	{
		info.data_file += endian_swap(p_fa->offset);
		p = (void *)info.data_file;
		ft_putstr(info.filename);
		(p->magic == MH_CIGAM || p->magic == MH_CIGAM_64) ? ft_print_arch((int)
			endian_swap((uint32_t)p->cputype), (int)endian_swap((uint32_t)
				p->cpusubtype)) : ft_print_arch(p->cputype, p->cpusubtype);
		ft_core(info);
		info.data_file -= endian_swap(p_fa->offset);
		++p_fa;
	}
	info.fat = 0;
	return (0);
}
