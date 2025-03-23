
#include "push_swap.h"

int distance_w_rot(t_stack_node *stack)
{
    int distance;

    distance = 0;
    if (stack == NULL || stack->head)
        return (distance);
    while (!stack->head)
    {
        distance++;
        stack = stack->prev;
    }
    return (distance);
}


int distance_w_rev_rot(t_stack_node *stack)
{
    int distance;

    distance = 0;
    if (stack == NULL || stack->head)
        return (distance);
    while (!stack->head)
    {
        distance++;
        stack = stack->next;
    }
    return (distance);
}


