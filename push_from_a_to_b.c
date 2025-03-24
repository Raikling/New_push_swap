
#include "push_swap.h"

static t_move	*find_cheapest_node_move(t_stack_node **a)
{
	t_move	*cheapest_move;

	if (a == NULL)
		return (NULL);
	cheapest_move = &((*a)->move);
	if (*a == (*a)->next)
		return (cheapest_move);
	*a = (*a)->next;
	while ((*a)->head != true)
	{
		if (cheapest_move->steps > (*a)->move.steps)
			cheapest_move = &((*a)->move);
		*a = (*a)->next;
	}
	return (cheapest_move);
}

static void	do_rotates(t_stack_node **a, t_stack_node **b, t_move *move)
{
	while (move->rot_a > 0 && move->rot_b > 0)
	{
		move->rot_a--;
		move->rot_b--;
		rr(a, b);
	}
	while (move->rot_a > 0)
	{
		move->rot_a--;
		ra(a);
	}
	while (move->rot_b > 0)
	{
		move->rot_b--;
		rb(b);
	}
}

static void	do_rev_rotates(t_stack_node **a, t_stack_node **b, t_move *move)
{
	while (move->rot_a < 0 && move->rot_b < 0)
	{
		move->rot_a++;
		move->rot_b++;
		rrr(a, b);
	}
	while (move->rot_a < 0)
	{
		move->rot_a++;
		rra(a);
	}
	while (move->rot_b < 0)
	{
		move->rot_b++;
		rrb(b);
	}
}



void	push_from_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_move	*move;

	if (a == NULL)
		return ;
	fill_move(*a, *b);
	*a = (*a)->next;
	while ((*a)->head != true)
	{
		fill_move(*a, *b);
		*a = (*a)->next;
	}
	move = find_cheapest_node_move(a);
	do_rotates(a, b, move);
	do_rev_rotates(a, b, move);
	pb(a, b);
}