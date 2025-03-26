
#include "push_swap.h"


// void sort_three(t_stack_node **stack)
// {
//     int	top;
// 	int	middle;
// 	int	bottom;

// 	top = (*stack)->value;
// 	middle = (*stack)->next->value;
// 	bottom = (*stack)->prev->value;
// 	if (middle < bottom && middle < top && bottom > top)
// 		sa(stack);
// 	else if (top > middle && top > bottom && middle > bottom)
// 	{
// 		sa(stack);
// 		rra(stack);
// 	}
// 	else if (top > middle && top > bottom && middle < bottom)
// 		ra(stack);
// 	else if (top < middle && top < bottom && middle > bottom)
// 	{
// 		sa(stack);
// 		ra(stack);
// 	}
// 	else if (top < middle && top > bottom && middle > bottom)
// 		rra(stack);
// }

void sort_three(t_stack_node **stack)
{
    int top;
    int middle;
    int bottom;

    top = (*stack)->value;
    middle = (*stack)->next->value;
    bottom = (*stack)->prev->value;

    if (top > middle && middle > bottom)
    {
        sa(stack);
        rra(stack);
    }
    else if (top > middle && top > bottom && middle < bottom)
        ra(stack);
    else if (top > middle && middle < bottom && top < bottom)
        sa(stack);
    else if (top < middle && middle > bottom && top < bottom)
    {
        sa(stack);
        ra(stack);
    }
    else if (top < middle && middle > bottom && top > bottom)
        rra(stack);
}


void	turk(t_stack_node **a, t_stack_node **b)
{
	if (is_a_sorted(*a))
		return ;
	else if (is_a_ordered(*a))
	{
		finalize_a(a);
		return ;
	}
	while (!is_a_ordered(*a))
		push_from_a_to_b(a, b);
	emptying_b(a, b);
	finalize_a(a);
}