#include "ft_nm.h"
#include <unistd.h>

static inline void endian_swap(unsigned int* x)
{
	*x = (*x>>(unsigned int)24) | 
		((*x<<(unsigned int)8) & 0x00FF0000) |
		((*x>>(unsigned int)8) & 0x0000FF00) |
		(*x<<(unsigned int)24);
}

static void	ft_nlist(unsigned int nsyms, unsigned int symoff, unsigned int stroff, char *ptr)
{
	char 						*string;
	struct nlist				*tab;
	unsigned long				i;
	t_list						*p_list;
	t_list						*h_list;
	unsigned int				tmp;

	p_list = NULL;
	h_list = NULL;

	printf("nsyms[%u] symoff[%u] stroff[%u]\n", nsyms, symoff, stroff);
	endian_swap(&nsyms);
	endian_swap(&symoff);
	endian_swap(&stroff);
	printf("nsyms[%u] symoff[%u] stroff[%u]\n", nsyms, symoff, stroff);
	// exit(-1);
	tab = (void *)((char *)ptr + symoff);
	string = ptr + stroff;
	i = 0;
	while(i < nsyms)
	{
		printf("%lu\n", i);

		if (tab[i].n_type & N_STAB)
			 ;
		else if ((tab[i].n_type & N_TYPE) || tab[i].n_type & N_EXT)
		{
			if (p_list == NULL)
			{
				p_list = ft_memalloc(sizeof(t_list));
				h_list = p_list;
			}
			else
			{	
				p_list->next = ft_memalloc(sizeof(t_list));
				p_list = p_list->next;
			}
			p_list->n_value = tab[i].n_value;
			endian_swap((unsigned int *)&(p_list->n_value));
			p_list->type = 'Z';//get_type_litle(&tab[i]);
			tmp	= tab[i].n_un.n_strx;
			endian_swap(&tmp);
			p_list->ptr = ft_strdup(string + tmp);
			reverse(p_list->ptr, ft_strlen(p_list->ptr));
			// p_list->ptr = ft_strrev(p_list->ptr);
		}
		i++;
	}
	// sort_list(h_list);
	printf("%s\n", "test");
	simple_print_32(h_list);
	printf("%s\n", "test");

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
			p_sync = (void*)p_lc;
			printf("nsyms[%u] symoff[%u] stroff[%u]\n", p_sync->nsyms, p_sync->symoff, p_sync->stroff);
			ft_nlist(p_sync->nsyms, p_sync->symoff, p_sync->stroff, ptr);
			break;
		}
		size = p_lc->cmdsize;
		endian_swap(&size);
		p_lc = (void *)(((char *)p_lc) + size);
		++i;
	}
}
