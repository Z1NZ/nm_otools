#include "ft_nm.h"
#include <stdlib.h>

void	*reverse(char *ptr, size_t len)
{
	char	*rev;

	rev = (char *)malloc((unsigned long)len + 1);
	rev = ft_memcpy(rev, ptr, len);
	rev[len + 1] = '\0';
	ft_strrev(rev);
	return (rev);
}
