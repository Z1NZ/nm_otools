#include "ft_nm.h"

void	ft_core_fat(t_file_info info)
{
	struct fat_header	*p_fh;
	struct fat_arch		*p_fa;
	uint32_t			n_arch;

	p_fh = (void *)info.data_file;
	p_fa = (void *)(p_fh + 1);
	n_arch = p_fh->nfat_arch;
	while(n_arch)
	{
		if (n_arch == 1)
		{	
			info.data_file += p_fa->offset;
			ft_core(info);// faire attention au retour de sur ft_core
			info.data_file -= p_fa->offset;
		}
		++p_fa;
		--n_arch;
	}
}
