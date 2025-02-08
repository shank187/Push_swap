#include "push_swap.h"

void print_content(t_list *head)
{
	t_list *ptr = head;
	int i = 0;
	while(ptr)
	{
		printf("node %i : %i\n",i, ptr -> content);
		ptr = ptr -> next;
		i++;
	}
}