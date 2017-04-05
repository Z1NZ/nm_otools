#include "ft_nm.h"

void	ft_core(t_file_info info)
{
	uint32_t  				magic_number;

	magic_number = *(uint32_t *)((void *)(info.data_file));
	ft_print_hexa_32(magic_number);// test 
	ft_putstr_fd(info.filename, 2);
	if (magic_number == MH_MAGIC) //big endian
	{
		ft_putstr(" test MH_MAGIC\n");
		ft_core_32(info);
	}
	else if (magic_number == MH_CIGAM)//little endian
	{
		ft_putstr(" test MH_CIGAM\n");
		ft_core_32_litle(info);
	}
	else if (magic_number == MH_MAGIC_64) //big endian
	{

		ft_putstr(" test MH_MAGIC_64\n");
		ft_core_64(info);
	}
	else if (magic_number == MH_CIGAM_64)//little endian
	{
		 ft_putstr(" test MH_CIGAM_64\n");
		ft_core_64_litle(info);
	}
	else if (magic_number == FAT_MAGIC) //big endian
	{
		 ft_putstr(" test FAT_MAGIC\n");
		ft_core_fat(info);
	}
	else if (magic_number == FAT_CIGAM) //little endian
	{
		 ft_putstr(" test FAT_CIGAM\n");
		ft_core_fat_litle(info);
	}
	else
	{
		if (info.filename)
		{
			ft_putstr_fd(info.filename, 2);
			ft_putstr_fd(" : The file was not recognized as a valid object file\n", 2);
		}
		else
			ft_putstr_fd("not recognized part of fat_binary ", 2);
	}

}
