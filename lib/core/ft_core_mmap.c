#include "ft_nm.h"
#include <sys/mman.h>

void	ft_core_mmap(int fd, t_file_info info)
{
	if ((info.data_file = mmap(0, (size_t)(info.data_stat.st_size), PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		ft_error_errno("ft_core mmap", NULL);
		exit(-1) ;
	}
	ft_core(info);
	if (munmap(info.data_file, (size_t)(info.data_stat.st_size)) == -1)
	{
		ft_error_errno("ft_core munmap", NULL);
		exit(-1) ;
	}
}
