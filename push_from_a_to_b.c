
#include "push_swap.h"


static t_move *get_cheapest_node(t_stack_node **a)
{
    t_move *cheapest;

    if (!a)
        return (NULL);
    cheapest = &((*a)->move); 
    if (*a == (*a)->next)
        return (cheapest);
    *a = (*a)->next;
    while ((*a)->head)
    {
        if (cheapest->steps > (*a)->move.steps)
            cheapest = &((*a)->move);
        *a = (*a)->next;
    }
    return (cheapest);
}


static void do_rotate(t_stack_node **a, t_stack_node **b, t_move *move)
{
    printf("rot_a: %d, rot_b: %d\n", move->rot_a, move->rot_b);
    while (move->rot_a > 0 && move->rot_b > 0)
    {
        rr(a, b);
        move->rot_a--;
        move->rot_b--;
    }
    while (move->rot_a > 0)
    {
        ra(a);
        move->rot_a--;
    }
    while (move->rot_b > 0)
    {
        rb(b);
        move->rot_b--;
    }
}

static void do_rev_rotate(t_stack_node **a, t_stack_node **b, t_move *move)
{
    printf("rot_a: %d, rot_b: %d\n", move->rot_a, move->rot_b);
    while (move->rot_a < 0 && move->rot_b < 0)
    {
        rrr(a, b);
        move->rot_a++;
        move->rot_b++;
    }
    while (move->rot_a < 0)
    {
        rra(a);
        move->rot_a++;
    }
    while (move->rot_b < 0)
    {
        rrb(b);
        move->rot_b++;
    }
}

void push_from_a_to_b(t_stack_node **a, t_stack_node **b)
{
    t_move *move;

    if (!a)
        return ;
    optimal_rotations(*a, *b);
    *a = (*a)->next;
    while ((*a)->head)
    {
        optimal_rotations(*a, *b);
        *a = (*a)->next;
    }
    move = get_cheapest_node(a);
    do_rotate(a, b, move);
    do_rev_rotate(a, b, move);
    pb(a, b);
}