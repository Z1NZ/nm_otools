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

static void		printer_nb(uint32_t offset, char *ptr, uint32_t len )
{
	while(len)
	{
		ft_print_hexa_uchar((unsigned char)ptr[offset]);
		offset++;
		len--;
	}

}

static int		section(struct segment_command *seg, t_file_info info)
{
	char			*ptr;
	uint32_t		i;
	uint32_t		j;
	uint32_t		jump;
	struct section *sect;

	i = 0;
	ptr = NULL;
	sect = (void *)(seg + 1);
	while(i < seg->nsects)
	{
		if (ft_strcmp(sect->sectname, SECT_TEXT) == 0 && ft_strcmp(sect->segname, SEG_TEXT) == 0)
		{
			ft_putstr(info.filename);
			ft_putstr(":\nContents of (__TEXT,__text) section");
			ptr = (char *)(info.data_file + sect->offset);
			i = 0;
			j = sect->addr;
			if (sect->align == 2)
				jump = sect->size % 4;
			else
				jump = 1;
			while (i < sect->size)
			{
				if ((i % 16) == 0)
				{
					ft_putstr("\n");
					ft_print_hexa_32(j);
					ft_putstr("\t");
					j += 16;
				}
				if (!jump)
				{
					printer_nb(i, ptr, 4);
					i += 4;
				}
				else
				{
					ft_print_hexa_uchar((unsigned char)ptr[i]);
					i++;
				}
				ft_putstr(" ");
			}
			ft_putstr("\n");
			return(0);
		}
		sect = (void *)(sect + 1);
		i++;
	}
	return(1);
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
