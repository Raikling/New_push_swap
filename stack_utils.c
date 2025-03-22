
#include "push_swap.h"


t_stack_node	*find_last(t_stack_node *stack) 
{
	if (!stack)
		return (NULL);
	while (stack->next) 
		stack = stack->next;
	return (stack);
}


