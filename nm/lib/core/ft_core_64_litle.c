/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_64_litle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:37:39 by srabah            #+#    #+#             */
/*   Updated: 2017/05/15 14:37:41 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"
#include <unistd.h>
#define T_TYPE tab[i[0]].n_type

static inline uint64_t		endian_swap_long(uint64_t x)
{
	x = ((x << 8) & 0xFF00FF00FF00FF00ULL) |
		((x >> 8) & 0x00FF00FF00FF00FFULL);
	x = ((x << 16) & 0xFFFF0000FFFF0000ULL) |
		((x >> 16) & 0x0000FFFF0000FFFFULL);
	return (x << 32) | (x >> 32);
}

static inline unsigned int	endian_swap(unsigned int x)
{
	x = (x >> (unsigned int)24) |
		((x << (unsigned int)8) & 0x00FF0000) |
		((x >> (unsigned int)8) & 0x0000FF00) |
		(x << (unsigned int)24);
	return (x);
}

static void					ft_nlist(struct symtab_command *sc,
	t_file_info info, t_count count_f)
{
	struct nlist_64				*tab;
	long						i[2];
	t_list						*p_list[2];

	p_list[0] = NULL;
	p_list[1] = NULL;
	tab = (void *)((char *)info.data_file + endian_swap(sc->symoff));
	i[0] = -1;
	i[1] = endian_swap(sc->nsyms);
	while (++i[0] < i[1])
	{
		if ((((char *)&tab[i[0]]) - info.data_file) > info.data_stat.st_size)
			return (ft_error_recognized(info.filename));
		else if (!(T_TYPE & N_STAB) && ((T_TYPE & N_TYPE) || T_TYPE & N_EXT))
		{
			p_list[0] = new_list(p_list[0], &p_list[1]);
			p_list[0]->n_value = endian_swap_long(tab[i[0]].n_value);
			p_list[0]->type = get_type_64(&tab[i[0]], count_f);
			p_list[0]->ptr = (info.data_file + endian_swap(sc->stroff) +
				endian_swap(tab[i[0]].n_un.n_strx));
			p_list[0]->ptr = p_list[0]->ptr;
		}
	}
	p_list[0] = NULL;
	list_display_64(p_list[1]);
}

static inline	int			count_flag_64(t_count *count,
	struct load_command *lc, t_file_info info)
{
	struct segment_command_64	*sc;
	struct section_64			*s;
	uint32_t					i[2];

	sc = (void *)lc;
	s = (void*)((char *)(sc + 1));
	i[0] = 0;
	i[1] = endian_swap(sc->nsects);
	while (i[0] < i[1])
	{
		if ((((char *)&(s[i[0]])) - info.data_file) > info.data_stat.st_size)
			return (ft_error_recognized(info.filename));
		if (!ft_strcmp(s[i[0]].sectname, SECT_TEXT) &&
			!ft_strcmp(s[i[0]].segname, SEG_TEXT))
			count->text = count->k + 1;
		else if (!ft_strcmp(s[i[0]].sectname, SECT_DATA) &&
			!ft_strcmp(s[i[0]].segname, SEG_DATA))
			count->data = count->k + 1;
		else if (!ft_strcmp(s[i[0]].sectname, SECT_BSS) &&
			!ft_strcmp(s[i[0]].segname, SEG_DATA))
			count->bss = count->k + 1;
		i[0]++;
		count->k++;
	}
	return (0);
}

int							ft_core_64_litle(t_file_info info)
{
	struct mach_header_64	*p_h;
	struct load_command		*p_lc;
	uint32_t				i;
	uint32_t				len;
	t_count					count_f;

	p_h = (void *)info.data_file;
	i = 0;
	p_lc = (struct load_command *)(p_h + 1);
	len = endian_swap(p_h->sizeofcmds);
	ft_memset(&count_f, 0, sizeof(t_count));
	while (i++ < len)
	{
		if (((char *)(p_lc) - info.data_file) > info.data_stat.st_size)
			return (ft_error_recognized(info.filename));
		if (endian_swap(p_lc->cmd) == LC_SYMTAB)
		{
			ft_nlist((void*)p_lc, info, count_f);
			break ;
		}
		if (endian_swap(p_lc->cmd) == LC_SEGMENT_64)
			count_flag_64(&count_f, p_lc, info);
		p_lc = (void *)(((char *)p_lc) + endian_swap(p_lc->cmdsize));
	}
	return (0);
}
