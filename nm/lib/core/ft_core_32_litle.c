/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_32_litle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 14:52:08 by srabah            #+#    #+#             */
/*   Updated: 2017/05/16 14:52:09 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"
#include <unistd.h>
#define T_TYPE tab[i[0]].n_type
#define DATA info.data_file

static inline unsigned int	es(unsigned int x)
{
	x = (x >> (unsigned int)24) |
		((x << (unsigned int)8) & 0x00FF0000) |
		((x >> (unsigned int)8) & 0x0000FF00) |
		(x << (unsigned int)24);
	return (x);
}

static int					ft_nlist(struct symtab_command *sc,
	t_count count_f, t_file_info info)
{
	struct nlist				*tab;
	long						i[2];
	t_list						*p[2];

	p[0] = NULL;
	p[1] = NULL;
	tab = (void *)((char *)info.data_file + es(sc->symoff));
	i[0] = -1;
	i[1] = es(sc->nsyms);
	while (++i[0] < i[1])
	{
		if ((((char *)&tab[i[0]]) - info.data_file) > info.data_stat.st_size)
			return (ft_error_recognized(info.filename));
		else if (!(T_TYPE & N_STAB) && ((T_TYPE & N_TYPE) || T_TYPE & N_EXT))
		{
			p[0] = new_list(p[0], &p[1]);
			p[0]->n_value = es(tab[i[0]].n_value);
			p[0]->type = get_type(&tab[i[0]], count_f);
			p[0]->ptr = (DATA + es(sc->stroff) + es(tab[i[0]].n_un.n_strx));
			p[0]->ptr = p[0]->ptr;
		}
	}
	p[0] = NULL;
	list_display(p[1]);
	return (1);
}

static inline int			count_flag(t_count *count,
	struct load_command *lc, t_file_info info)
{
	struct segment_command	*sc;
	struct section			*s;
	uint32_t				i[2];

	sc = (void *)lc;
	s = (void *)(sc + 1);
	i[0] = 0;
	i[1] = es(sc->nsects);
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

int							ft_core_32_litle(t_file_info info)
{
	struct mach_header			*p_h;
	struct load_command			*p_lc;
	uint32_t					i;
	uint32_t					len;
	t_count						count_f;

	p_h = (void *)info.data_file;
	i = 0;
	p_lc = (struct load_command *)(p_h + 1);
	len = es(p_h->sizeofcmds);
	ft_memset(&count_f, 0, sizeof(t_count));
	while (i++ < len)
	{
		if (((char *)(p_lc) - info.data_file) > info.data_stat.st_size)
			return (ft_error_recognized(info.filename));
		if (es(p_lc->cmd) == LC_SYMTAB)
		{
			ft_nlist((void*)p_lc, count_f, info);
			break ;
		}
		if (es(p_lc->cmd) == LC_SEGMENT)
			count_flag(&count_f, p_lc, info);
		p_lc = (void *)(((char *)p_lc) + es(p_lc->cmdsize));
	}
	return (0);
}
