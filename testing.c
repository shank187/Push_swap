#include "push_swap.h"

void print_content(t_list *head)
{
	t_list *ptr = head;
	int i = 0;
	while(ptr)
	{
		printf("node %i : %i |index = %i|\n",i, ptr -> content, ptr -> index);
		ptr = ptr -> next;
		i++;
	}
}

int get_index(t_list *top_a, int number)
{
	t_list *ptr;
	int max_rank, min_rank;

	max_rank = 0;
	min_rank = 0;
	ptr = top_a;
	while(ptr) 
	{
		if(number > (ptr -> content))
			if ((ptr -> index > max_rank))
				max_rank = ptr -> index;
		if(number < (ptr -> content))
		{
			if(min_rank > ptr -> index)
				min_rank = (ptr -> index); 
			(ptr -> index)++;
		}
		ptr = ptr -> next;
	}
	if(min_rank)
		return(min_rank);
	return(max_rank + 1);
}

int is_sorted(t_list *top_a)
{
	int last;

	last = INT_MIN;
	while(top_a)
	{
		if (top_a -> content < last)
			return(0);
		top_a = top_a -> next;
	}
	return(1);
}
