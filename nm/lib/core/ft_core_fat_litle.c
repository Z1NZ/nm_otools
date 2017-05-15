/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_fat_litle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:04:20 by srabah            #+#    #+#             */
/*   Updated: 2017/05/15 15:04:21 by srabah           ###   ########.fr       */
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

void						ft_print_sub_arm(cpu_subtype_t sub)
{
	if (sub == CPU_SUBTYPE_ARM_V7)
		ft_putstr(" (for architecture armv7):\n");
	else if (sub == CPU_SUBTYPE_ARM_V7S)
		ft_putstr(" (for architecture armv7s):\n");
	else
		ft_putstr(" (for architecture armv):\n");
}

void						ft_print_sub_ppc(cpu_subtype_t sub)
{
	if (sub == CPU_SUBTYPE_POWERPC_ALL)
		ft_putstr(" (for architecture ppc):\n");
	else
		ft_putstr(" (for architecture ):\n");
}

void						ft_print_arch(cpu_type_t type, cpu_subtype_t sub)
{
	if (type == CPU_TYPE_ANY)
		ft_putstr(" (for architecture any):");
	else if (type == CPU_TYPE_VAX)
		ft_putstr(" (for architecture vax):\n");
	else if (type == CPU_TYPE_MC680x0)
		ft_putstr(" (for architecture mc680x0):\n");
	else if (type == CPU_TYPE_I386)
		ft_putstr(" (for architecture i386):\n");
	else if (type == CPU_TYPE_MC98000)
		ft_putstr(" (for architecture mc98000):");
	else if (type == CPU_TYPE_HPPA)
		ft_putstr(" (for architecture hppa):\n");
	else if (type == CPU_TYPE_ARM)
		ft_print_sub_arm(sub);
	else if (type == CPU_TYPE_ARM64)
		ft_putstr(" (for architecture arm64):\n");
	else if (type == CPU_TYPE_MC88000)
		ft_putstr(" (for architecture mc88000):\n");
	else if (type == CPU_TYPE_SPARC)
		ft_putstr(" (for architecture sparc):\n");
	else if (type == CPU_TYPE_POWERPC)
		ft_print_sub_ppc(sub);
	else if (type == CPU_TYPE_POWERPC64)
		ft_putstr(" (for architecture powerpc64):\n");
}

int							ft_core_fat_litle(t_file_info info)
{
	struct fat_header	*p_fh;
	struct fat_arch		*p_fa;
	uint32_t			n_arch;
	struct mach_header	*p_h;

	p_fh = (void *)info.data_file;
	p_fa = (void *)(p_fh + 1);
	n_arch = endian_swap(p_fh->nfat_arch);
	if (find_arch(info))
		return (0);
	while (n_arch)
	{
		info.data_file += endian_swap(p_fa->offset);
		p_h = (void *)info.data_file;
		ft_putstr("\n");
		ft_putstr(info.filename);
		if (p_h->magic == MH_CIGAM || p_h->magic == MH_CIGAM_64)
			ft_print_arch((cpu_type_t)endian_swap((unsigned int)p_h->cputype),
					(cpu_subtype_t)endian_swap((unsigned int)p_h->cpusubtype));
		else
			ft_print_arch(p_h->cputype, p_h->cpusubtype);
		ft_core(info);
		info.data_file -= endian_swap(p_fa->offset);
		++p_fa;
		--n_arch;
	}
	return (0);
}
