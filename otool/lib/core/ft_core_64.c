/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_64.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 20:10:47 by srabah            #+#    #+#             */
/*   Updated: 2017/05/20 20:10:51 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"
#include <unistd.h>
#include <stdio.h>

static void		put_sect(t_file_info info, struct section_64 *sect)
{
	char				*ptr;
	uint64_t			i[2];

	if (!info.fat)
	{
		ft_putstr(info.filename);
		ft_putstr(":\n");
	}
	ft_putstr("Contents of (__TEXT,__text) section");
	ptr = (char *)(info.data_file + sect->offset);
	i[1] = sect->addr;
	i[0] = 0;
	while (i[0] < sect->size)
	{
		if ((i[0] % 16) == 0)
		{
			ft_putstr("\n");
			ft_print_hexa_64(i[1]);
			ft_putstr("\t");
			i[1] += 16;
		}
		ft_print_hexa_uchar((unsigned char)ptr[i[0]]);
		ft_putstr(" ");
		i[0]++;
	}
}

static int		section64(struct segment_command_64 *seg, t_file_info info)
{
	uint64_t			i;
	struct section_64	*sect;

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

int				ft_core_64(t_file_info info)
{
	struct mach_header_64		*p_h;
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
		if (p_lc->cmd == LC_SEGMENT_64)
			if (section64((void*)p_lc, info) == 0)
				return (0);
		p_lc = (void *)(((char *)p_lc) + p_lc->cmdsize);
		++i;
	}
	return (0);
}
