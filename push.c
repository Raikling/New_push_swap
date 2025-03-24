
#include "push_swap.h"

static t_stack_node *pop_top_node(t_stack_node **src)
{
    t_stack_node *top;

    if (*src == (*src)->next)
    {
        top = *src;
        *src = NULL;
        return (top);
    }
    else
    {
        top = *src;
        (*src)->prev->next = (*src)->next;
        (*src)->next->prev = (*src)->prev;
        (*src) = (*src)->next;
        (*src)->head = true;
    }
    return (top);
}

static int push(t_stack_node **src, t_stack_node **dst)
{
    t_stack_node *new_head;

    if (!(*src))
        return (0);
    if (!(*dst))
    {
        *dst = pop_top_node(src);
        (*dst)->next = *dst;
        (*dst)->prev = *dst;
        (*dst)->head = true;
    }
    else
    {
        new_head = pop_top_node(src);
        (*dst)->prev->next = new_head;
        new_head->prev = (*dst)->prev;
        new_head->next = *dst;
        (*dst)->prev = new_head;
        (*dst)->head = false;
        new_head->head = true;
        (*dst) = new_head;
    }
    return (1);
}



void pa(t_stack_node **a, t_stack_node **b)
{
    if (push(b, a))
        ft_printf("pa\n");
}

void pb(t_stack_node **a, t_stack_node **b)
{
    if (push(a, b))
        ft_printf("pb\n");
}