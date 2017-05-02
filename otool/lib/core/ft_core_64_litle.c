#include "ft_otool.h"
#include <unistd.h>


static inline uint64_t endian_swap_long(uint64_t x)
{
	x = ((x << 8) & 0xFF00FF00FF00FF00ULL ) | ((x >> 8) & 0x00FF00FF00FF00FFULL );
	x = ((x << 16) & 0xFFFF0000FFFF0000ULL ) | ((x >> 16) & 0x0000FFFF0000FFFFULL );
	return (x << 32) | (x >> 32);
}

static inline unsigned int endian_swap(unsigned int x)
{
	x = (x>>(unsigned int)24) | 
		((x<<(unsigned int)8) & 0x00FF0000) |
		((x>>(unsigned int)8) & 0x0000FF00) |
		(x<<(unsigned int)24);
	return(x);
}

static int		section64(struct segment_command_64 *seg, t_file_info info)
{
	char		*ptr;
	uint64_t	i;
	uint64_t	j;

	struct section_64 *sect;
	i = 0;
	ptr = NULL;
	sect = (void *)(seg + 1);
	while(i < seg->nsects)
	{
		if (ft_strcmp(sect->sectname, SECT_TEXT) == 0 && ft_strcmp(sect->segname, SEG_TEXT) == 0)
		{
			if (!info.fat)
			{
				ft_putstr(info.filename);
				ft_putstr(":\n");
			}
			ft_putstr("Contents of (__TEXT,__text) section");
			ptr = (char *)(info.data_file + endian_swap(sect->offset));
			j =  endian_swap_long(sect->addr);
			i = 0;
			while (i <  endian_swap_long(sect->size))
			{
				if ((i % 16) == 0)
				{
					ft_putstr("\n");
					ft_print_hexa_64(j);
					ft_putstr("\t");
					j += 16;
				}
				ft_print_hexa_uchar((unsigned char)ptr[i]);
				ft_print_hexa_uchar((unsigned char)ptr[i + 1]);
				ft_print_hexa_uchar((unsigned char)ptr[i + 2]);
				ft_print_hexa_uchar((unsigned char)ptr[i + 3]);
				i += 4;
				ft_putstr(" ");
			}
			ft_putstr("\n");
			return(0);
		}
		sect = (void *)(sect + 1);
		i++;
	}
	return(1);
}

int		ft_core_64_litle(t_file_info info)
{
	struct mach_header_64		*p_h;
	struct load_command 		*p_lc;
	uint32_t					i;
	uint32_t					len;
	t_count						count_f;


	p_h = (void *)info.data_file;
	i = 0;
	p_lc = (struct load_command *)(p_h + 1);
	len = endian_swap(p_h->sizeofcmds);
	count_f.text = 0;
	count_f.data = 0;
	count_f.bss = 0;
	count_f.k = 0;
	while(i < len)
	{
		if (((char *)(p_lc) - info.data_file) > info.data_stat.st_size)
		{
			ft_error_recognized(info.filename);
			return (1);
		}
 		if (endian_swap(p_lc->cmd) == LC_SEGMENT_64)
			if (section64((void*)p_lc, info) == 0)
				return(0);
		p_lc = (void *)(((char *)p_lc) + endian_swap(p_lc->cmdsize));
		++i;
	}
	return(0);
}
