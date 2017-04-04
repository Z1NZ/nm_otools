#include "ft_nm.h"
#include <unistd.h>

static inline void endian_swap(unsigned int* x)
{
	*x = (*x>>(unsigned int)24) | 
		((*x<<(unsigned int)8) & 0x00FF0000) |
		((*x>>(unsigned int)8) & 0x0000FF00) |
		(*x<<(unsigned int)24);
}

static void	ft_nlist(unsigned int nsyms, unsigned int symoff, unsigned int stroff, char *ptr, t_count count_f)
{
	char 						*string;
	struct nlist				*tab;
	unsigned long				i;
	t_list						*p_list;
	t_list						*h_list;
	uint32_t					tmp;

	p_list = NULL;
	h_list = NULL;

	endian_swap(&nsyms);
	endian_swap(&symoff);
	endian_swap(&stroff);
	tab = (void *)((char *)ptr + symoff);
	string = ptr + stroff;
	i = 0;
	while(i < nsyms)
	{
		if (tab[i].n_type & N_STAB)
			 ;
		else if ((tab[i].n_type & N_TYPE) || tab[i].n_type & N_EXT)
		{
			if (p_list == NULL)
			{
				if ((p_list = ft_memalloc(sizeof(t_list))) == NULL)
					ft_error_errno("ft_memalloc", NULL);
				h_list = p_list;
			}
			else
			{
				if ((p_list->next = ft_memalloc(sizeof(t_list))) == NULL)
					ft_error_errno("ft_memalloc", NULL);
				p_list = p_list->next;
			}
			p_list->n_value = tab[i].n_value;
			endian_swap((unsigned int *)&(p_list->n_value));
			p_list->type = get_type(&tab[i], count_f);
			tmp	= tab[i].n_un.n_strx;
			endian_swap(&tmp);
			p_list->ptr = ft_strdup(string + tmp);
			reverse(p_list->ptr, ft_strlen(p_list->ptr));
		}
		i++;
	}
	if (h_list)
	{
		sort_list(h_list);
		simple_print_32(h_list);
		ft_free_list_litle(h_list);
	}
}


static inline	void		count_flag(t_count *count, struct load_command *lc)
{
	struct segment_command 	*sc;
	struct section 			*s;
	uint32_t				j;
	uint32_t				len;

	sc = (void *)lc;
	s = (void *)(sc + 1);
	j = 0;
	len = sc->nsects;
	endian_swap(&len);
	while (j < len)
	{
		if(!ft_strcmp(s[j].sectname, SECT_TEXT) && !ft_strcmp(s[j].segname, SEG_TEXT))
			count->text = count->k + 1;
		else if(!ft_strcmp(s[j].sectname, SECT_DATA) && !ft_strcmp(s[j].segname, SEG_DATA))
			count->data = count->k + 1;
		else if(!ft_strcmp(s[j].sectname, SECT_BSS) && !ft_strcmp(s[j].segname, SEG_DATA))
			count->bss = count->k + 1;
		j++;
		count->k++;
	}
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
	t_count						count_f;


	p_h = (void *)ptr;
	i = 0;
	p_lc = (struct load_command *)(p_h + 1);
	len = p_h->sizeofcmds;
	endian_swap(&len);
	count_f.text = 0;
	count_f.data = 0;
	count_f.bss = 0;
	count_f.k = 0;
	while(i < len)
	{
		sym = p_lc->cmd;
		endian_swap(&sym);
		if (sym == LC_SYMTAB)
		{
			p_sync = (void*)p_lc;
			ft_nlist(p_sync->nsyms, p_sync->symoff, p_sync->stroff, ptr, count_f);
			break;
		}
 		if (sym == LC_SEGMENT)
 			count_flag(&count_f, p_lc);
		size = p_lc->cmdsize;
		endian_swap(&size);
		p_lc = (void *)(((char *)p_lc) + size);
		++i;
	}
}
