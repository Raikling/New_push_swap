
#include "push_swap.h"

static int max(int x, int y)
{
    if (x > y)
        return (x);
    return (y);
}



void optimal_rotations(t_stack_node *a, t_stack_node *b)
{
    a->move.rot_a = distance_w_rot(a);
    a->move.rot_b = distance_w_rot(new_b_pos(b, a));
    a->move.steps = max(a->move.rot_a, a->move.rot_b);
    if (distance_w_rot(a) + distance_w_rev_rot(new_b_pos(b, a)) < a->move.steps)
    {
        a->move.rot_a = distance_w_rot(a);
        a->move.rot_b = distance_w_rev_rot(new_b_pos(b, a));
        a->move.steps = a->move.rot_a + a->move.rot_b;
    }
    if (distance_w_rev_rot(a) + distance_w_rot(new_b_pos(b, a)) < a->move.steps)
    {
        a->move.rot_a = distance_w_rev_rot(a);
        a->move.rot_b = distance_w_rot(new_b_pos(b, a));
        a->move.steps = a->move.rot_a + a->move.rot_b;
    }
    if (max(distance_w_rev_rot(a), distance_w_rev_rot(new_b_pos(b, a))) < a->move.steps)
    {
        a->move.rot_a = distance_w_rev_rot(a);
        a->move.rot_b = distance_w_rev_rot(new_b_pos(b, a));
        a->move.steps = max(a->move.rot_a, a->move.rot_b);
    }
}