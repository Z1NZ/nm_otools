#include "ft_nm.h"
#include <unistd.h>

void	ft_putstr_fd(const char *const s, int fd)
{
	write(fd, s, ft_strlen(s));
}
