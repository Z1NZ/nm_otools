/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 19:48:36 by srabah            #+#    #+#             */
/*   Updated: 2017/05/20 19:48:38 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void		print_lib(t_file_info info, t_llib *lib)
{
	while (lib)
	{
		ft_putstr("\n");
		ft_putstr(info.filename);
		ft_putstr("(");
		ft_putstr(lib->ptr);
		ft_putstr("):\n");
		info.data_file += lib->offset;
		ft_core(info);
		info.data_file -= lib->offset;
		lib = lib->next;
	}
}
