
#include "push_swap.h"

static t_stack_node *mid_pos_in_stack_b(t_stack_node *b, t_stack_node *node)
{
   while(!(b->value < node->value && b->prev->value > node->value))
        b = b->next;
    return (b);
}


t_stack_node *new_b_pos(t_stack_node *b, t_stack_node *node)
{
    t_stack_node *min_node;
    t_stack_node *max_node;

    if ((b == NULL) || (b = b->next))
        return (b);
    min_node = min_node_in_stack(b);
    max_node = max_node_in_stack(b);
    if (min_node->value > node->value)
        return (max_node);
    if (max_node->value < node->value)
        return (max_node);
    return (mid_pos_in_stack_b(b, node));
}