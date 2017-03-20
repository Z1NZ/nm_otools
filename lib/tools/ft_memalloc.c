
#include "ft_nm.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*new_space;

	if (!size)
		return (NULL);
	new_space = (void*)malloc(size * sizeof(void*));
	if (!new_space)
		return (NULL);
	ft_memset((unsigned char*)new_space, 0, size);
	return (new_space);
}
