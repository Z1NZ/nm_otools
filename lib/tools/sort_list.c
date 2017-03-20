#include "ft_nm.h"

void	sort_list(t_list *ptr)
{
	t_list *tmp;
	tmp = ptr;
	while (tmp && tmp->next)
	{
		if (ft_strcmp(tmp->ptr, tmp->next->ptr) > 0)
		{
			ft_list_swap(tmp, tmp->next);
			tmp = ptr;
		}
		else
			tmp = tmp->next;
	}
}
