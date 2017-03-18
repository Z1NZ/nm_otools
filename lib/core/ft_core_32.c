
#include "ft_nm.h"

void	ft_core_32(char *ptr)
{
	struct mach_header *p_h;
	struct segment_command *p_sc;

	p_h = (void *)ptr;
	printf("number of load %d all the load %d\n",
	 p_h->ncmds,p_h->sizeofcmds);
	p_sc = (void *)(p_h + 1);
	printf("seg_name%s\n", p_sc->segname);
}
