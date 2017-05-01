#include "ft_otool.h"

void	free_lib(t_llib *lib)
{
	t_llib *tmp;

	while(lib)
	{
		tmp = lib;
		lib = lib->next;
		free(tmp);
	}
}
