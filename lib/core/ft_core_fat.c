#include "ft_nm.h"

void	ft_core_fat(char *ptr)
{
	struct fat_header *p_fh;

	p_fh = (void *)ptr;
	ft_putnbr((int)p_fh->nfat_arch);
	ft_putstr("ft_core_fat");
}
