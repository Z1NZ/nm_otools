#include "ft_nm.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = (char*)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (p != NULL)
		ft_strcpy(p, s1);
	return (p);
}
