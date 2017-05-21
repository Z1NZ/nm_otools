/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_32.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 22:39:04 by srabah            #+#    #+#             */
/*   Updated: 2017/04/30 22:39:08 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"
#include <unistd.h>

static int				section(struct segment_command *seg, t_file_info info)
{
	long			i;
	long			j;
	struct section	*sect;

	i = -1;
	sect = (void *)(seg + 1);
	while (++i < seg->nsects)
	{
		if (!ft_strcmp(sect->sectname, SECT_TEXT) && !ft_strcmp(sect->segname, SEG_TEXT))
		{
			if (!info.fat)
			{
				ft_putstr(info.filename);
				ft_putstr(":\n");
			}
			ft_putstr("Contents of (__TEXT,__text) section");
			i = -1;
			j = sect->addr;
			while (++i < sect->size)
			{
				if ((i % 16) == 0)
				{
					ft_putstr("\n");
					ft_print_hexa_32((uint32_t)j);
					ft_putstr("\t");
					j += 16;
				}
				ft_print_hexa_uchar((uint8_t)(info.data_file + sect->offset)[i]);
				ft_putstr(" ");
			}
			ft_putstr("\n");
			return (0);
		}
		sect = (void *)(sect + 1);
	}
	return (1);
}

int						ft_core_32(t_file_info info)
{
	struct mach_header			*p_h;
	struct load_command			*p_lc;
	uint32_t					i;

	p_h = (void *)info.data_file;
	i = 0;
	p_lc = (struct load_command *)(p_h + 1);
	while (i < p_h->sizeofcmds)
	{
		if (((char *)(p_lc) - info.data_file) > info.data_stat.st_size)
		{
			ft_error_recognized(info.filename);
			return (1);
		}
		if (p_lc->cmd == LC_SEGMENT)
			if ((section((void*)p_lc, info)) == 0)
				return (0);
		p_lc = (void *)(((char *)p_lc) + p_lc->cmdsize);
		++i;
	}
	return (0);
}
