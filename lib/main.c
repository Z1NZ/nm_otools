#include "ft_nm.h"
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_openner(char *argv)
{
	int fd;
	struct stat buff;
	if ((fd = open(argv, O_RDONLY)) > 0)
	{
		if (fstat(fd, &buff)!= -1)
		{
			if (S_ISREG(buff.st_mode))
				ft_core_mmap(fd, &buff);
			else 
				ft_error_st_mode(buff.st_mode, argv);
		}
		else
			ft_error_errno("ft_openner fstat ", argv);
		if (close(fd) == -1)
			ft_error_errno("ft_openner close ", argv);
	}
	else
		ft_error_errno("ft_openner open ", argv);
}

int		main(int argc, char *argv[])
{
	unsigned int	i;

	i = 1;
	if (argc > 1)
	{
		while(argv[i])
		{
			ft_openner(argv[i]);
			++i;
		}
	}
	else
		ft_openner("./a.out");
	return (0);
}
