#include "ft_otool.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = (char*)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (p != NULL)
		ft_strcpy(p, s1);
	else
		ft_error_errno("ft_strdup", NULL);
	return (p);
}
