#include "ft_nm.h"
#include <sys/mman.h>

void	ft_core_mmap(int fd, struct stat *buff)
{
	char *ptr;
	if ((ptr = mmap(0, (size_t)buff->st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		ft_error_errno("ft_core mmap", NULL);
		exit(-1) ;
	}
	ft_core(ptr);
	if (munmap(ptr, (size_t)buff->st_size) == -1)
	{
		ft_error_errno("ft_core munmap", NULL);
		exit(-1) ;
	}
}
