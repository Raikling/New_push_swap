
#include "push_swap.h"

static int swap(t_stack_node **stack)
{
    if ((*stack == NULL) || ((*stack) == (*stack)->next))
        return (0);
    if ((*stack)->prev == (*stack)->next)
    {
        (*stack)->head = false;
        (*stack) = (*stack)->next;
        (*stack)->head = true;
    }
    else
    {
        (*stack)->head = false;
        (*stack)->prev->next = (*stack)->next;
        (*stack)->next->prev = (*stack)->prev;
        (*stack)->prev = (*stack)->next;
        (*stack)->next = (*stack)->next->next;
        (*stack)->prev->next = (*stack);
        (*stack)->next->prev = (*stack);
        (*stack) = (*stack)->prev;
        (*stack)->head = true;
    }
    return  (1);
}

void sa(t_stack_node **a)
{
    if (swap(a))
        ft_printf("sa\n");
}

void sb(t_stack_node **b)
{
    if (swap(b))
        ft_printf("sb\n");
}

void ss(t_stack_node **a,t_stack_node **b)
{
    if (swap(a) + swap(b))
        ft_printf("ss\n");
}

