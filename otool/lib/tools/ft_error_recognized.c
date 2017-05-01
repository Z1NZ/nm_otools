
#include "ft_otool.h"

void	ft_error_recognized(const char *ptr)
{	
	ft_putstr_fd("ft_otool: ", 2);
	ft_putstr_fd(ptr, 2);
	ft_putstr_fd(ERROR, 2);
	return ;
}
