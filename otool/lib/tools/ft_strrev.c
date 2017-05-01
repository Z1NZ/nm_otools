#include "ft_otool.h"

char		*ft_strrev(char *str)
{
	char				a;
	unsigned long		f;
	unsigned long		d;

	f = (ft_strlen(str) - 1);
	d = 0;
	while (d < f && d != f)
	{
		a = str[f];
		str[f] = str[d];
		str[d] = a;
		f--;
		d++;
	}
	return (str);
}
