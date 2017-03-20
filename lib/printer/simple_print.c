#include "ft_nm.h"
#include <unistd.h>

void	simple_print(t_list *ptr)
{
	while(ptr)
	{
		if (ptr->n_value)
			ft_print_hexa(ptr->n_value);
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
