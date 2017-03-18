#include "ft_nm.h"

size_t	ft_strlen(const char *const s)
{
	char const	*p_s = s;

	while (*p_s)
		p_s++;
	return ((size_t)(p_s - s));
}
