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
static int		ft_get_size(struct ar_hdr *ptr)
{
	char *tmp;

	tmp = ft_strstr(ptr->ar_name, "/");
	tmp++;
	return(ft_atoi(tmp));
}


static void 	ft_print_mod(t_file_info info)
{
	struct ar_hdr 	*ar;
	int				i;

	i = 0;
	ar = (void *)info.data_file;
	i = ft_get_size(ar);
	ft_putstr("(");
	ft_putstr((char *)(ar + 1));
	ft_putstr(")\n");
	info.data_file += sizeof(struct ar_hdr) + (unsigned long)i;
	ft_core(info);
	info.data_file -= sizeof(struct ar_hdr) + (unsigned long)i;
}

int		ft_core_static_lib(t_file_info info)
{
	struct ar_hdr 					*ptr;
	struct dylib_table_of_contents *rlib;
	char							*symdef;
	uint32_t					i;

	symdef = NULL;
	i = 0;
	ptr =  (void*)((char *)info.data_file + 8);
	symdef = (char *)(ptr + 1);
	if (ft_strcmp(symdef, SYMDEF_SORTED) == 0)
	{

		i =	*(uint32_t *) (void *)(symdef + ft_get_size(ptr));
		rlib = (struct dylib_table_of_contents *)(void *)(symdef + ft_get_size(ptr) + 4);
		while((char *)rlib < (info.data_file + i))
		{
			ft_putstr("\n");
			ft_putstr(info.filename);
			info.data_file += rlib->module_index;
			ft_print_mod(info);
			info.data_file -= rlib->module_index;
			rlib++;
		}
	}
	return(0);
}
