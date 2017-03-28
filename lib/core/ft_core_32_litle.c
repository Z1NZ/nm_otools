#include "ft_nm.h"
#include <unistd.h>

static inline void endian_swap(unsigned int* x)
{
    *x = (*x>>(unsigned int)24) | 
        ((*x<<(unsigned int)8) & 0x00FF0000) |
        ((*x>>(unsigned int)8) & 0x0000FF00) |
        (*x<<(unsigned int)24);
}

void	ft_core_32_litle(char *ptr)
{
	struct mach_header			*p_h;
	struct load_command 		*p_lc;
	struct symtab_command		*p_sync;
	uint32_t					i;
	uint32_t					len;
	uint32_t					sym;
	uint32_t					size;


	p_h = (void *)ptr;
	i = 0;
	p_lc = (struct load_command *)(p_h + 1);
	len = p_h->sizeofcmds;
	endian_swap(&len);
	while(i < len)
	{
		sym = p_lc->cmd;
		endian_swap(&sym);
		if (sym == LC_SYMTAB)
		{
			printf("%s\n", "mega nova");
			p_sync = (void*)p_lc;
			ft_nlist(p_sync->nsyms, p_sync->symoff, p_sync->stroff, ptr);
			break;
		}
		size = p_lc->cmdsize;
		endian_swap(&size);
		p_lc = (void *)(((char *)p_lc) + size);
		++i;
	}
}
