#include "ft_nm.h"
#include <stdlib.h>

static inline void endian_swap(unsigned int* x)
{
	*x = (*x>>(unsigned int)24) | 
		((*x<<(unsigned int)8) & 0x00FF0000) |
		((*x>>(unsigned int)8) & 0x0000FF00) |
		(*x<<(unsigned int)24);
}

void	*reverse(char *ptr, size_t len)
{
	char	*rev;
	size_t	i;

	i = 0;
	rev = (char *)ft_memalloc((unsigned long)len + 1);
	rev = ft_memcpy(rev, ptr, len);
	while(i <= len)
	{
		endian_swap((unsigned int *) (void *)rev + i);
		i += 4;
	}
	return (rev);
}
