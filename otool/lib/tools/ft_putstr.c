#include "ft_otool.h"
#include <unistd.h>

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}
