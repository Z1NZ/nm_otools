/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 13:36:05 by srabah            #+#    #+#             */
/*   Updated: 2017/05/13 13:46:25 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

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
