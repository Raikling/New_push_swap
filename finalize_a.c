

#include "push_swap.h"

void	finalize_a(t_stack_node **a)
{
	t_stack_node	*min_node;

	min_node = min_node_in_stack(*a);
	if (distance_w_rot(min_node) < distance_w_rev_rot(min_node))
		while (min_node->head != true)
			ra(a);
	else
		while (min_node->head != true)
			rra(a);
}