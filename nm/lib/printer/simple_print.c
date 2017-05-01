#include "ft_nm.h"
#include <unistd.h>

void	simple_print_64(t_list *ptr)
{
	while(ptr)
	{
		if (ptr->n_value || ptr->type == 't' || ptr->type == 'T')
			ft_print_hexa_64(ptr->n_value);
		else
			write(1, "                ", 16);
		write(1," ", 1);
		write(1, &(ptr->type), 1);
		write(1, " ", 1);
		ft_putstr(ptr->ptr);
		ft_putstr("\n");
		ptr = ptr->next;
	}
}


void	simple_print_32(t_list *ptr)
{
	while(ptr)
	{
		if (ptr->n_value || ptr->type == 't' || ptr->type == 'T')
			ft_print_hexa_32(ptr->n_value);
		else
			write(1, "        ", 8);
		write(1," ", 1);
		write(1, &(ptr->type), 1);
		write(1, " ", 1);
		ft_putstr(ptr->ptr);
		ft_putstr("\n");
		ptr = ptr->next;
	}
}
