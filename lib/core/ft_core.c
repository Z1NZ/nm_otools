#include "ft_nm.h"

void	ft_core(char *ptr, size_t len)
{
	uint32_t  magic_number;
	char *tmp;

	magic_number = *(uint32_t *)((void *)ptr);

	ft_print_hexa_32(magic_number);// test
	if (magic_number == MH_MAGIC) //big endian
	{
		ft_putstr("MH_MAGIC\n");
		ft_core_32(ptr);
	}
	else if (magic_number == MH_CIGAM)//little endian
	{
		ft_putstr("test MH_CIGAM\n");
		tmp = reverse(ptr, len);
		ft_core_32(tmp);
	}
	else if (magic_number == MH_MAGIC_64) //big endian
		ft_core_64(ptr);
	else if (magic_number == MH_CIGAM_64)//little endian
	{
		ft_putstr("test MH_CIGAM_64\n");
		tmp = reverse(ptr, len);
		ft_core_64(ptr);		
	}
	else if (magic_number == FAT_MAGIC) //big endian
		ft_putstr("test 0xCAFEBABE\n");
	else if (magic_number == FAT_CIGAM) //little endian
		ft_putstr("test 0xbebafeca\n");
	else if (magic_number == FAT_MAGIC_64)
		ft_putstr("test FAT_MAGIC_64\n");
	else if (magic_number == FAT_CIGAM_64)
		ft_putstr("test FAT_CIGAM_64\n");
}
