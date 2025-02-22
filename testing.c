#include "push_swap.h"

void print_content(t_list *head, int more)
{
	t_list *ptr = head;
	int i = 0;
	while(ptr)
	{
		if (!more)
			printf("node %i : %i |index = %i|\n",i, ptr -> content, ptr -> index);
		else{
			printf("pos %i|value %i|index %i|target %i|   \n",i, ptr -> content, ptr -> index, ptr -> target_pos, ptr -> cost_a, ptr -> cost_b);

		}
		ptr = ptr -> next;
		i++;
	}
}



