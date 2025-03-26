
#include "push_swap.h"

int	distance_w_rot(t_stack_node *node)
{
	int	distance;

	distance = 0;
	if (node == NULL || node->head == true)
		return (distance);
	while (node->head != true)
	{
		++distance;
		node = node->prev;
	}
	return (distance);
}

int	distance_w_rev_rot(t_stack_node *node)
{
	int	distance;

	distance = 0;
	if (node == NULL || node->head == true)
		return (distance);
	while (node->head != true)
	{
		++distance;
		node = node->next;
	}
	return (distance);
}