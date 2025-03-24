
#include "push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	len;

	if (stack == NULL)
		return (0);
	if (stack == stack->next)
		return (1);
	stack = stack->next;
	len = 1;
	while (stack->head != true)
	{
		++len; //change is later
		stack = stack->next;
	}
	return (len);
}