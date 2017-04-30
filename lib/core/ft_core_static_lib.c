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

void				ft_push_mod_back(t_llib *lib, t_llib *tmp)
{
	while(lib->next)
		lib = lib->next;
	lib->next = tmp;
}

t_llib 		*ft_add_mod(t_file_info info, t_llib *lib, unsigned int len)
{
	struct ar_hdr 	*ar;
	int				i;
	t_llib		*tmp;


	if ((tmp = ft_memalloc(sizeof(t_llib))) == NULL)
		ft_error_errno("ft_memalloc", NULL);
	i = 0;
	ar = (void *)info.data_file;
	i = ft_get_size(ar);
	tmp->ptr = (char *)(ar + 1);
	tmp->offset = sizeof(struct ar_hdr) + (unsigned long)i + len;
	if (lib == NULL)
		return(tmp);
	else
	{
		ft_push_mod_back(lib, tmp);
		return(lib);
	}
}

int		ft_core_static_lib(t_file_info info)
{
	struct ar_hdr 					*ptr;
	struct dylib_table_of_contents *rlib;
	char							*symdef;
	uint32_t						i;
	t_llib						*lib;

	symdef = NULL;
	lib = NULL;
	i = 0;
	ptr =  (void*)((char *)info.data_file + 8);
	symdef = (char *)(ptr + 1);
	if (ft_strcmp(symdef, SYMDEF_SORTED) == 0)
	{

		i =	*(uint32_t *) (void *)(symdef + ft_get_size(ptr));
		rlib = (struct dylib_table_of_contents *)(void *)(symdef + ft_get_size(ptr) + 4);
		while((char *)rlib < (info.data_file + i))
		{
			info.data_file += rlib->module_index;
			lib = ft_add_mod(info, lib, rlib->module_index);
			info.data_file -= rlib->module_index;
			rlib++;
		}
	}
	if (lib)
	{
		ft_sort_lib(lib);
		print_lib(info, lib);
	}
	return(0);
}
