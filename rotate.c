
#include "push_swap.h"

static int rotate(t_stack_node **stack)
{
    if ((*stack == NULL) || ((*stack) == (*stack)->next))
        return (0);
    (*stack)->head = false;
    (*stack) = (*stack)->next;
    (*stack)->head = true;
    return (1);
}

void ra(t_stack_node **a)
{
    if (rotate(a))
        ft_printf("ra\n");
}

void rb(t_stack_node **b)
{
    if (rotate(b))
        ft_printf("rb\n");
}

void rr(t_stack_node **a, t_stack_node **b)
{
    if (rotate(a) + rotate(b))
        ft_printf("rr\n");
}