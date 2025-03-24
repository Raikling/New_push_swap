
#include "push_swap.h"

// int	is_a_ordered(t_stack_node *a)
// {
// 	t_stack_node	*min_node;
// 	t_stack_node	*max_node;
// 	int		count;

// 	if (!a)
// 		return (1);
// 	min_node = min_node_in_stack(a);
// 	max_node = max_node_in_stack(a);
// 	count = 1;
// 	while (min_node != max_node)
// 	{
// 		if (min_node->value > min_node->next->value)
// 			return (0);
// 		min_node = min_node->next;
// 		++count; //change it later
// 	}
// 	if (count == stack_len(a))
// 		return (1);
// 	return (0);
// }

int	is_a_ordered(t_stack_node *a)
{
	t_stack_node	*min_node;
	t_stack_node	*max_node;
	int		count;

	if (!a)
		return (true);
	min_node = min_node_in_stack(a);
	max_node = max_node_in_stack(a);
	count = 1;
	while (min_node != max_node)
	{
		if (min_node->value > min_node->next->value)
			return (false);
		min_node = min_node->next;
		++count;
	}
	if (count == stack_len(a))
		return (true);
	return (false);
}