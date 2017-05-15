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
	char						*string;
	struct nlist_64				*tab;
	unsigned long				i[2];
	t_list						*p_list;
	t_list						*h_list;

	p_list = NULL;
	h_list = NULL;
	tab = (void *)((char *)info.data_file + endian_swap(sc->symoff));
	string = info.data_file + endian_swap(sc->stroff);
	i[0] = 0;
	i[1] = endian_swap(sc->nsyms);
	while (i[0] < i[1])
	{
		if ((((char *)&tab[i[0]]) - info.data_file) > info.data_stat.st_size)
		{
			ft_error_recognized(info.filename);
			return ;
		}
		if (tab[i[0]].n_type & N_STAB)
			;
		else if ((tab[i[0]].n_type & N_TYPE) || tab[i[0]].n_type & N_EXT)
		{
			if (p_list == NULL)
			{
				if ((p_list = ft_memalloc(sizeof(t_list))) == NULL)
					ft_error_errno("ft_memalloc", NULL);
				h_list = p_list;
			}
			else
			{
				if ((p_list->next = ft_memalloc(sizeof(t_list))) == NULL)
					ft_error_errno("ft_memalloc", NULL);
				p_list = p_list->next;
			}
			p_list->n_value = endian_swap_long(tab[i[0]].n_value);
			p_list->type = get_type_64(&tab[i[0]], count_f);
			p_list->ptr = (string + endian_swap(tab[i[0]].n_un.n_strx));
			p_list->ptr = p_list->ptr;
		}
		i[0]++;
	}
	p_list = NULL;
	if (h_list)
	{
		sort_list(h_list);
		simple_print_32(h_list);
		ft_free_list(h_list);
	}
}

static inline	void		count_flag_64(t_count *count,
	struct load_command *lc, t_file_info info)
{
	struct segment_command_64	*sc;
	struct section_64			*s;
	uint32_t					j;
	uint32_t					len;

	sc = (void *)lc;
	s = (void*)((char *)(sc + 1));
	j = 0;
	len = endian_swap(sc->nsects);
	while (j < len)
	{
		if ((((char *)&(s[j])) - info.data_file) > info.data_stat.st_size)
		{
			ft_error_recognized(info.filename);
			return ;
		}
		if (!ft_strcmp(s[j].sectname, SECT_TEXT) && !ft_strcmp(s[j].segname, SEG_TEXT))
			count->text = count->k + 1;
		else if (!ft_strcmp(s[j].sectname, SECT_DATA) && !ft_strcmp(s[j].segname, SEG_DATA))
			count->data = count->k + 1;
		else if (!ft_strcmp(s[j].sectname, SECT_BSS) && !ft_strcmp(s[j].segname, SEG_DATA))
			count->bss = count->k + 1;
		j++;
		count->k++;
	}
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
	count_f.text = 0;
	count_f.data = 0;
	count_f.bss = 0;
	count_f.k = 0;
	while (i < len)
	{
		if (((char *)(p_lc) - info.data_file) > info.data_stat.st_size)
		{
			ft_error_recognized(info.filename);
			return (1);
		}
		if (endian_swap(p_lc->cmd) == LC_SYMTAB)
		{
			ft_nlist((void*)p_lc, info, count_f);
			break ;
		}
		if (endian_swap(p_lc->cmd) == LC_SEGMENT_64)
			count_flag_64(&count_f, p_lc, info);
		p_lc = (void *)(((char *)p_lc) + endian_swap(p_lc->cmdsize));
		++i;
	}
	return (0);
}
