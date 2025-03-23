
#include "push_swap.h"

void sort_three(t_stack_node **stack)
{
    t_stack_node *biggest_node;

    biggest_node = max_node_in_stack(*stack);
    if (biggest_node == *stack)
        ra(stack);
    else if ((*stack)->next == biggest_node)
        rra(stack);
    if ((*stack)->value > (*stack)->next->value)
        sa(stack); 
}

void turk(t_stack_node **a, t_stack_node **b)
{
    if (is_a_ascen(*a))
        return ;
    else if (is_a_ordered(*a))
    {
        finish(a);
        return ;
    }
    while (!is_a_ordered(*a))
        push_from_a_to_b(a, b);   
    //empting_b(a, b);
    
}
