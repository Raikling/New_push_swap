
#include "push_swap.h"




static t_stack_node	*mid_pos_in_stack_a(t_stack_node *stack, t_stack_node *node)
{
	while (!(stack->value > node->value
			&& stack->prev->value < node->value))
		stack = stack->prev;
	return (stack);
}

t_stack_node	*node_new_pos_a(t_stack_node *a, t_stack_node *node)
{
	t_stack_node	*min_node;
	t_stack_node	*max_node;

	if (!node)
		return (a);
	if (a == NULL)
		return (a);
	if (a == (a)->next)
		return (a);
	min_node = min_node_in_stack(a);
	max_node = max_node_in_stack(a);
	if (min_node->value > node->value)
		return (min_node);
	if (max_node->value < node->value)
		return (min_node);
	return (mid_pos_in_stack_a(a, node));
}



void	empty_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*max_node_b;
	t_stack_node	*new_pos_on_a;

	if (*b == NULL)
		return ;
	max_node_b = max_node_in_stack(*b);
	if (dist_w_rot(max_node_b) > dist_w_rev_rot(max_node_b))
		while (max_node_b->head != true)
			rrb(b);
	else
		while (max_node_b->head != true)
			rb(b);
	while (*b)
	{
		new_pos_on_a = node_new_pos_a(*a, *b);
		if (dist_w_rot(new_pos_on_a) < dist_w_rev_rot(new_pos_on_a))
			while (new_pos_on_a != *a)
				ra(a);
		else
			while (new_pos_on_a != *a)
				rra(a);
		pa(a, b);
	}
}