
#include "push_swap.h"

int	dist_w_rot(t_stack_node *node)
{
	int	dist;

	dist = 0;
	if (node == NULL || node->head == true)
		return (dist);
	while (node->head != true)
	{
		++dist;
		node = node->prev;
	}
	return (dist);
}

int	dist_w_rev_rot(t_stack_node *node)
{
	int	dist;

	dist = 0;
	if (node == NULL || node->head == true)
		return (dist);
	while (node->head != true)
	{
		++dist;
		node = node->next;
	}
	return (dist);
}