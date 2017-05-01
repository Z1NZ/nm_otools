
#include "ft_otool.h"
#include <unistd.h>

void			ft_putnbr(int n)
{
	int	count;
	int	u_nbr;
	char c;

	count = 0;
	u_nbr = n;
	if (n < 0)
	{
		write(1, "-", 1);
		u_nbr = -n;
	}
	if (u_nbr / 10)
		ft_putnbr(u_nbr / 10);
	c = (u_nbr % 10 + '0');
	write(1, &c, 1);
}
