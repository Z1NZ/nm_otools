#include "ft_nm.h"
#include <unistd.h>

void			pri_addr(unsigned long long number)
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
	addr[16] = '\0';
	while (i > -1)
	{
		write(1, &addr[i], 1);
		i--;
	}
}