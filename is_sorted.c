
#include "push_swap.h"

int	is_a_sorted(t_stack_node *a)
{
	if (a == NULL)
		return (true);
	while (a->next->head != true)
	{
		if (a->value > a->next->value)
			return (false);
		a = a -> next;
	}
	return (true);
}

int	is_b_sorted(t_stack_node *b)
{
	if (b == NULL)
		return (true);
	while (b->next->head != true)
	{
		if (b->value < b->next->value)
			return (false);
		b = b -> next;
	}
	return (true);
}