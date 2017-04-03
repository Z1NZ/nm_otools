#include "ft_nm.h"

void	ft_core(char *ptr)
{
	uint32_t  				magic_number;

	magic_number = *(uint32_t *)((void *)ptr);
	// ft_print_hexa_32(magic_number);// test 
	if (magic_number == MH_MAGIC) //big endian
	{
		// ft_putstr("test MH_MAGIC\n");
		ft_core_32(ptr);
	}
	else if (magic_number == MH_CIGAM)//little endian
	{
		// ft_putstr("test MH_CIGAM\n");
		ft_core_32_litle(ptr);
	}
	else if (magic_number == MH_MAGIC_64) //big endian
	{
		// ft_putstr("test MH_MAGIC_64\n");
		ft_core_64(ptr);
	}
	else if (magic_number == MH_CIGAM_64)//little endian
	{
		 // ft_putstr("test MH_CIGAM_64\n");
		ft_core_64_litle(ptr);
	}
	else if (magic_number == FAT_MAGIC) //big endian
		ft_core_fat(ptr);
	else if (magic_number == FAT_CIGAM) //little endian
		ft_core_fat_litle(ptr);

}
