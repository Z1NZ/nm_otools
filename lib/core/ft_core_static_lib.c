#include "ft_nm.h"
#include <ar.h>
#include <ranlib.h>






// typedef struct {
//     Elf64_Addr r_offset;
//     uint64_t   r_info;
// } Elf64_Rel;


    //  struct dylib_table_of_contents {
    //    uint32_t symbol_index;
    //    uint32_t module_index;
    // };



int		ft_core_static_lib(t_file_info info)
{
	struct ar_hdr 					*ptr;
	// struct ranlib					*rlib;
	struct dylib_table_of_contents *rlib;
	char							*symdef;
	uint32_t					i;

	symdef = NULL;
	i = 0;
	ptr =  (void*)((char *)info.data_file + 8);
	symdef = (char *)(ptr + 1);
	if (ft_strcmp(symdef, SYMDEF_SORTED) == 0)
	{	
		symdef = symdef + ft_strlen(SYMDEF_SORTED) + 1 + RANLIBSKEW;
		i = *(uint32_t *) (void *)symdef;
		rlib = (struct dylib_table_of_contents *)(void *)(symdef + 4);
		// dtc = (void *)((char *)(ptr + 21 + sizeof(i)));
		printf("\n%u ---> + %u\n", i, rlib->module_index);
		printf("%s\n", "bravo sofiane :)))))) ->");
	}
	return(0);
}
