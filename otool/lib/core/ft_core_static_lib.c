/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_static_lib.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 06:09:16 by srabah            #+#    #+#             */
/*   Updated: 2017/05/22 06:09:22 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"
#include <ar.h>
#include <ranlib.h>

static int		ft_get_size(struct ar_hdr *ptr)
{
	char	*tmp;

	tmp = ft_strstr(ptr->ar_name, "/");
	tmp++;
	return (ft_atoi(tmp));
}

void			ft_push_mod_back(t_llib *lib, t_llib *tmp)
{
	while (lib->next && lib->offset != tmp->offset)
		lib = lib->next;
	if (lib->offset == tmp->offset)
	{
		free(tmp);
		return ;
	}
	lib->next = tmp;
}

t_llib			*ft_add_mod(t_file_info info, t_llib *lib, uint32_t len)
{
	struct ar_hdr	*ar;
	int				i;
	t_llib			*tmp;

	tmp = NULL;
	if ((tmp = ft_memalloc(sizeof(t_llib))) == NULL)
		ft_error_errno("ft_memalloc", NULL);
	i = 0;
	ar = (void *)info.data_file;
	i = ft_get_size(ar);
	tmp->ptr = (char *)(ar + 1);
	tmp->offset = sizeof(struct ar_hdr) + (unsigned long)i + len;
	if (lib == NULL)
		return (tmp);
	else
	{
		ft_push_mod_back(lib, tmp);
		return (lib);
	}
}

static int		ft_display_lib(t_file_info info, t_llib *lib)
{
	if (lib)
	{
		ft_sort_lib(lib);
		print_lib(info, lib);
		free_lib(lib);
	}
	return (0);
}

int				ft_core_static_lib(t_file_info info)
{
	struct ar_hdr					*ptr;
	struct dylib_table_of_contents	*rlib;
	char							*symdef;
	uint32_t						i;
	t_llib							*lib;

	lib = NULL;
	ptr = (void*)((char *)info.data_file + 8);
	symdef = (char *)(ptr + 1);
	if (ft_strcmp(symdef, SYMDEF_SORTED) == 0)
	{
		symdef += ft_get_size(ptr);
		i = *(uint32_t *)(void *)(symdef);
		rlib = (struct dylib_table_of_contents *)(void *)(symdef + 4);
		if (((symdef + i) - info.data_file) > info.data_stat.st_size)
			return (ft_error_recognized(info.filename));
		while ((char *)rlib < (symdef + i))
		{
			info.data_file += rlib->module_index;
			lib = ft_add_mod(info, lib, rlib->module_index);
			info.data_file -= rlib->module_index;
			rlib++;
		}
	}
	return (ft_display_lib(info, lib));
}
