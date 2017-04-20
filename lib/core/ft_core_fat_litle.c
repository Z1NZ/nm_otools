#include "ft_nm.h"

static inline unsigned int endian_swap(unsigned int x)
{
	x = (x>>(unsigned int)24) | 
		((x<<(unsigned int)8) & 0x00FF0000) |
		((x>>(unsigned int)8) & 0x0000FF00) |
		(x<<(unsigned int)24);
	return(x);
}

int 	find_arch(t_file_info info)
{
	struct fat_header	*p_fh;
	struct fat_arch		*p_fa;
	uint32_t			n_arch;
	struct mach_header	*p_h;

	p_fh = (void *)info.data_file;
	p_fa = (void *)(p_fh + 1);
	n_arch = endian_swap(p_fh->nfat_arch);
	while(n_arch)
	{
		info.data_file += endian_swap(p_fa->offset);
		p_h = (void *)info.data_file;

		if (p_h->cputype == CPU_TYPE_X86_64)
		{
			ft_core(info);// faire attention au retour de sur ft_core
			return(1);
		}
		info.data_file -= endian_swap(p_fa->offset);
		++p_fa;
		--n_arch;
	}
	return (0);

}

void	ft_print_arch(cpu_type_t type)
{
	if (type == CPU_TYPE_ANY)
		ft_putstr(" (for architecture any):");
	else if (type == CPU_TYPE_VAX)
		ft_putstr(" (for architecture vax):\n");
	else if (type == CPU_TYPE_MC680x0)
		ft_putstr(" (for architecture mc680x0):\n");
	else if (type == CPU_TYPE_I386)
		ft_putstr(" (for architecture i386):\n");
	else if (type == CPU_TYPE_MC98000)
		ft_putstr(" (for architecture mc98000):");
	else if (type == CPU_TYPE_HPPA)
		ft_putstr(" (for architecture hppa):\n");
	else if (type == CPU_TYPE_MC88000)
		ft_putstr(" (for architecture mc88000):\n");
	else if (type == CPU_TYPE_SPARC)
		ft_putstr(" (for architecture sparc):\n");
	else if (type == CPU_TYPE_POWERPC)
		ft_putstr(" (for architecture ppc):\n");
	else if (type == CPU_TYPE_POWERPC64)
		ft_putstr(" (for architecture powerpc64):\n");
}

void	ft_core_fat_litle(t_file_info info)
{
	struct fat_header	*p_fh;
	struct fat_arch		*p_fa;
	uint32_t			n_arch;
	struct mach_header	*p_h;


	p_fh = (void *)info.data_file;
	p_fa = (void *)(p_fh + 1);
	n_arch = endian_swap(p_fh->nfat_arch);
	if (find_arch(info))
		return ;
	while(n_arch)
	{
		info.data_file += endian_swap(p_fa->offset);
		p_h = (void *)info.data_file;
		ft_putstr("\n");
		ft_putstr(info.filename);
		if (p_h->magic == MH_CIGAM || p_h->magic == MH_CIGAM_64)
			ft_print_arch((cpu_type_t)endian_swap((unsigned int)p_h->cputype));
		else
			ft_print_arch((cpu_type_t)p_h->cputype);
		ft_core(info);// faire attention au retour de sur ft_core
		info.data_file -= endian_swap(p_fa->offset);
		++p_fa;
		--n_arch;
	}
}
