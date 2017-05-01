#include <string.h>
#include "ft_otool.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*p_s1;
	const char	*p_s2 = s2;

	p_s1 = s1;
	while (n--)
		*p_s1++ = *p_s2++;
	return (s1);
}
