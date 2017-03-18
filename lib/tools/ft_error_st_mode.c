
#include "ft_nm.h"


void ft_error_st_mode(mode_t st_mode, char *name)
{
	ft_putstr_fd(name, 2);
	if (S_ISDIR(st_mode))
		ft_putstr_fd(": Is a directory\n", 2);
}
