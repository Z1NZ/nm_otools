
#include "ft_otool.h"

void ft_free_list(t_list *head)
{
	t_list *tmp;

	tmp = NULL;
	while(head)
	{
		tmp = head->next;
		free(head);
		head = NULL;
		head = tmp;
	}	
}

void ft_free_list_litle(t_list *head)
{
	t_list *tmp;

	tmp = NULL;
	while(head)
	{

		tmp = head->next;
		free(head->ptr);
		head->ptr = NULL;
		free(head);
		head = NULL;
		head = tmp;
	}	
}
