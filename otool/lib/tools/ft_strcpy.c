#include "ft_otool.h"

char	*ft_strcpy(char *s1, const char *s2)
{
	char	*s1_begin;

	s1_begin = s1;
	while ((*s1++ = *s2++))
		;
	return (s1_begin);
}
