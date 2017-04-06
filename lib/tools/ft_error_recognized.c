
#include "ft_nm.h"

void	ft_error_recognized(const char *ptr)
{	
	ft_putstr_fd("ft_nm: ", 2);
	ft_putstr_fd(ptr, 2);
	ft_putstr_fd(ERROR, 2);
	return ;
}
