
#include "ft_otool.h"
#include <unistd.h>

void ft_put_n_char(char *ptr, size_t nb)
{
	write(1, ptr, nb);
}
