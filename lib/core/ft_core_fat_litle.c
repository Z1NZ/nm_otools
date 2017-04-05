#include "ft_nm.h"

static inline unsigned int endian_swap(unsigned int x)
{
	x = (x>>(unsigned int)24) | 
		((x<<(unsigned int)8) & 0x00FF0000) |
		((x>>(unsigned int)8) & 0x0000FF00) |
		(x<<(unsigned int)24);
	return(x);
}

void	ft_core_fat_litle(t_file_info info)
{
	struct fat_header	*p_fh;
	struct fat_arch		*p_fa;
	uint32_t			n_arch;

	p_fh = (void *)info.data_file;
	p_fa = (void *)(p_fh + 1);
	n_arch = endian_swap(p_fh->nfat_arch);
	ft_putnbr((int)n_arch);
	ft_putstr("    n_arch\n");
	while(n_arch)
	{

		if (n_arch == 1)
		{
			ft_putnbr((int)endian_swap(p_fa->offset));
			info.data_file += endian_swap(p_fa->offset);
			ft_core(info);// faire attention au retour de sur ft_core
			info.data_file -= endian_swap(p_fa->offset);
		}
		++p_fa;
		--n_arch;
	}
}