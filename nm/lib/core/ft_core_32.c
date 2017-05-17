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

#include "ft_nm.h"
#include <unistd.h>

static inline int	ft_nlist(struct symtab_command *sc, t_count count_f,
	t_file_info info)
{
	char						*string;
	struct nlist				*tab;
	long						i;
	t_list						*p_list;
	t_list						*h_list;

	p_list = NULL;
	h_list = NULL;
	tab = (void *)((char *)info.data_file + sc->symoff);
	string = info.data_file + sc->stroff;
	i = -1;
	while (++i < sc->nsyms)
	{
		if ((((char *)&tab[i]) - info.data_file) > info.data_stat.st_size)
			return (ft_error_recognized(info.filename));
		if (tab[i].n_type & N_STAB)
			;
		else if ((tab[i].n_type & N_TYPE) || tab[i].n_type & N_EXT)
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
			p_list->n_value = tab[i].n_value;
			p_list->type = get_type(&tab[i], count_f);
			p_list->ptr = string + tab[i].n_un.n_strx;
		}
	}
	p_list = NULL;
	list_display(h_list);
	return (1);
}

static inline int	count_flag(t_count *count, struct load_command *lc,
	t_file_info info)
{
	struct segment_command	*sc;
	struct section			*s;
	uint32_t				i[2];

	sc = (void *)lc;
	s = (void *)(sc + 1);
	i[0] = 0;
	i[1] = sc->nsects;
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

int					ft_core_32(t_file_info info)
{
	struct mach_header			*p_h;
	struct load_command			*p_lc;
	uint32_t					i;
	t_count						count_f;

	p_h = (void *)info.data_file;
	i = 0;
	ft_memset(&count_f, 0, sizeof(t_count));
	p_lc = (struct load_command *)(p_h + 1);
	while (i < p_h->sizeofcmds)
	{
		if (((char *)(p_lc) - info.data_file) > info.data_stat.st_size)
			return (ft_error_recognized(info.filename));
		if (p_lc->cmd == LC_SYMTAB)
		{
			ft_nlist((void*)p_lc, count_f, info);
			break ;
		}
		if (p_lc->cmd == LC_SEGMENT)
			count_flag(&count_f, p_lc, info);
		p_lc = (void *)(((char *)p_lc) + p_lc->cmdsize);
		++i;
	}
	return (0);
}
