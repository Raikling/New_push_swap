
#include "push_swap.h"

t_stack_node *min_node_in_stack(t_stack_node *stack)
{
    t_stack_node *min_node;

    if (stack == NULL)
        return (0);
    min_node = stack;
    stack = stack->next;
    while (!stack->head)
    {
        if (min_node->value > stack->value)
            min_node = stack;
        stack = stack->next;
    }
    return (min_node);
}

t_stack_node *max_node_in_stack(t_stack_node *stack)
{
    t_stack_node *max_node;

    if (stack == NULL)
        return (0);
    max_node = stack;
    stack = stack->next;
    while (!stack->head)
    {
        if (max_node->value < stack->value)
            max_node = stack;
        stack = stack->next;
    }
    return (max_node);
}