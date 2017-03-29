
#include "ft_nm.h"

void ft_free_list(t_list *head)
{
	t_list *tmp;

	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}	
}

void ft_free_list_litle(t_list *head)
{
	t_list *tmp;

	while(head)
	{
		tmp = head->next;
		free(head->ptr);
		free(head);
		head = tmp;
	}	
}