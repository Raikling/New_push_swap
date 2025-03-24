
#include "push_swap.h"


static t_stack_node	*mid_pos_in_stack(t_stack_node *stack, t_stack_node *node)
{
	while (!(stack->value < node->value
			&& stack->prev->value > node->value))
		stack = stack->next;
	return (stack);
}

t_stack_node	*new_pos_b(t_stack_node *b, t_stack_node *node)
{
	t_stack_node	*min_node;
	t_stack_node	*max_node;

	if ((b == NULL) || (b == b->next))
		return (b);
	min_node = min_node_in_stack(b);
	max_node = max_node_in_stack(b);
	if (min_node->value > node->value)
		return (max_node);
	if (max_node->value < node->value)
		return (max_node);
	return (mid_pos_in_stack(b, node));
}

static int	max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}


void	fill_move(t_stack_node *a, t_stack_node *b)
{
	a->move.rot_a = dist_w_rot(a);
	a->move.rot_b = dist_w_rot(new_pos_b(b, a));
	a->move.steps = max(a->move.rot_a, a->move.rot_b);
	if (dist_w_rot(a) + dist_w_rev_rot(new_pos_b(b, a)) < a->move.steps)
	{
		a->move.rot_a = dist_w_rot(a);
		a->move.rot_b = -dist_w_rev_rot(new_pos_b(b, a));
		a->move.steps = a->move.rot_a - a->move.rot_b;
	}
	if (dist_w_rev_rot(a) + dist_w_rot(new_pos_b(b, a)) < a->move.steps)
	{
		a->move.rot_a = -dist_w_rev_rot(a);
		a->move.rot_b = dist_w_rot(new_pos_b(b, a));
		a->move.steps = -a->move.rot_a + a->move.rot_b;
	}
	if (max(dist_w_rev_rot(a), dist_w_rev_rot(new_pos_b(b, a))) < a->move.steps)
	{
		a->move.rot_a = -dist_w_rev_rot(a);
		a->move.rot_b = -dist_w_rev_rot(new_pos_b(b, a));
		a->move.steps = max(-a->move.rot_a, -a->move.rot_b);
	}
}