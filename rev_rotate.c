
#include "push_swap.h"

static int rev_rotate(t_stack_node **stack)
{
    if ((*stack == NULL) || ((*stack) == (*stack)->next))
        return (0);
    (*stack)->head = false;
    (*stack) = (*stack)->prev;
    (*stack)->head = true;
    return (1);
}


void rra(t_stack_node **a)
{
    if (rev_rotate(a))
        ft_printf("rra\n");
}

void rrb(t_stack_node **b)
{
    if (rev_rotate(b))
        ft_printf("rrb\n");
}

void rrr(t_stack_node **a, t_stack_node **b)
{
    if (rev_rotate(a) + rev_rotate(b))
        ft_printf("rrr\n");
}