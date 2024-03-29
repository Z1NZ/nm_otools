/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_32_litle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 20:09:57 by srabah            #+#    #+#             */
/*   Updated: 2017/05/20 20:09:59 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"
#include <unistd.h>

static inline unsigned int	endian_swap(unsigned int x)
{
	x = (x >> (unsigned int)24) |
		((x << (unsigned int)8) & 0x00FF0000) |
		((x >> (unsigned int)8) & 0x0000FF00) |
		(x << (unsigned int)24);
	return (x);
}

static void					hexa_sect(char *ptr, uint32_t i)
{
	ft_print_hexa_uchar((unsigned char)ptr[i]);
	ft_print_hexa_uchar((unsigned char)ptr[i + 1]);
	ft_print_hexa_uchar((unsigned char)ptr[i + 2]);
	ft_print_hexa_uchar((unsigned char)ptr[i + 3]);
	ft_putstr(" ");
}

static int					put_sect(t_file_info info, struct section *sect)
{
	uint32_t		i[2];
	char			*ptr;

	if (!info.fat)
	{
		ft_putstr(info.filename);
		ft_putstr(":\n");
	}
	ft_putstr("Contents of (__TEXT,__text) section");
	ptr = (char *)(info.data_file + endian_swap(sect->offset));
	i[0] = 0;
	i[1] = endian_swap(sect->addr);
	while (i[0] < endian_swap(sect->size))
	{
		if ((i[0] % 16) == 0)
		{
			ft_putstr("\n");
			ft_print_hexa_32(i[1]);
			ft_putstr("\t");
			i[1] += 16;
		}
		hexa_sect(ptr, i[0]);
		i[0] += 4;
	}
	return (0);
}

static int					section(struct segment_command *seg,
	t_file_info info)
{
	uint32_t		i;
	struct section	*sect;

	i = 0;
	sect = (void *)(seg + 1);
	while (i < seg->nsects)
	{
		if (!ft_strcmp(sect->sectname, SECT_TEXT) &&
			!ft_strcmp(sect->segname, SEG_TEXT))
		{
			put_sect(info, sect);
			ft_putstr("\n");
			return (0);
		}
		sect = (void *)(sect + 1);
		i++;
	}
	return (1);
}

int							ft_core_32_litle(t_file_info info)
{
	struct mach_header			*p_h;
	struct load_command			*p_lc;
	uint32_t					i;
	uint32_t					len;

	p_h = (void *)info.data_file;
	i = 0;
	p_lc = (struct load_command *)(p_h + 1);
	len = endian_swap(p_h->sizeofcmds);
	while (i < len)
	{
		if (((char *)(p_lc) - info.data_file) > info.data_stat.st_size)
		{
			ft_error_recognized(info.filename);
			return (1);
		}
		if (endian_swap(p_lc->cmd) == LC_SEGMENT)
			if ((section((void*)p_lc, info)) == 0)
				return (0);
		p_lc = (void *)(((char *)p_lc) + endian_swap(p_lc->cmdsize));
		++i;
	}
	return (0);
}
