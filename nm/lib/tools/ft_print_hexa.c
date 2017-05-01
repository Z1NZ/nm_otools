#include "ft_nm.h"
#include <unistd.h>

void			ft_print_hexa_32(unsigned long number)
{
	static char	base[] = "0123456789abcdef";
	int			current_rest;
	char		addr[9];
	int			i;

	current_rest = 0;
	i = 0;
	while (number)
	{
		current_rest = number % 16;
		addr[i] = base[current_rest];
		number /= 16;
		i++;
	}
	while(i < 8)
	{
		addr[i] = '0';
		i++;
	}
	while (--i > -1)
		write(1, &addr[i], 1);
}


void			ft_print_hexa_64(unsigned long long number)
{
	static char	base[] = "0123456789abcdef";
	int			current_rest;
	char		addr[17];
	int			i;

	current_rest = 0;
	i = 0;
	while (number)
	{
		current_rest = number % 16;
		addr[i] = base[current_rest];
		number /= 16;
		i++;
	}
	while(i < 16)
	{
		addr[i] = '0';
		i++;
	}
	while (--i > -1)
		write(1, &addr[i], 1);
}
