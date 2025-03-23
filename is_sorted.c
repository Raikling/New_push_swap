
#include "push_swap.h"

int is_a_ascen(t_stack_node *a)
{
    if (!a)
        return (1);
    while (!a->next->head)
    {
        if (a->value > a->next->value)
            return (0);
        a = a->next;
    }
    return (1);
}

int is_b_descen(t_stack_node *b)
{
    if (!b)
        return (1);
    while (!b->next->head)
    {
        if (b->value < b->next->value)
            return (0);
        b = b->next;
    }
    return (1);
}