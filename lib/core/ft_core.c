#include "ft_nm.h"

void	ft_core(char *ptr)
{
	uint32_t  magic_number;

	magic_number = *(uint32_t *)((void *)ptr);
	if (magic_number == MH_MAGIC)
	{
		printf("%s\n", "binary 32bit");
		ft_core_32(ptr);
	}
	else if (magic_number == MH_MAGIC_64)
	{
		printf("%s\n", "binary 64bit");
		ft_core_64(ptr);
	}
}
