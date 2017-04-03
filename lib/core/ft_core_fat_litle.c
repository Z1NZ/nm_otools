#include "ft_nm.h"

static inline void endian_swap(unsigned int* x)
{
	*x = (*x>>(unsigned int)24) | 
		((*x<<(unsigned int)8) & 0x00FF0000) |
		((*x>>(unsigned int)8) & 0x0000FF00) |
		(*x<<(unsigned int)24);
}

void	ft_core_fat_litle(char *ptr)
{
	struct fat_header	*p_fh;
	struct fat_arch		*p_fa;
	uint32_t			n_arch;
	uint32_t			offset;

	p_fh = (void *)ptr;
	p_fa = (void *)(p_fh + 1);
	n_arch = p_fh->nfat_arch;
	endian_swap(&n_arch);
	while(n_arch)
	{
		offset = p_fa->offset; 
		endian_swap(&(offset));
		if (n_arch == 1)
			ft_core(ptr+ offset);
		++p_fa;
		--n_arch;
	}
}
