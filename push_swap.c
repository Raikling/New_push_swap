#include "push_swap.h"

void print_list(t_stack_node *head)
{
    if (!head)
        return;

    t_stack_node *current = head;
    printf("\nA: \n%d ", current->value);
    printf("rot_a: %d, rot_b: %d, steps: %d\n", current->move.rot_a, current->move.rot_b, current->move.steps);
    printf("distance_w_rot: %d\n", distance_w_rot(current));
    printf("distance_w_rev_rot: %d\n", distance_w_rev_rot(current));
    current = current->next;
    while (current != head)
    {
        printf("%d ", current->value);
        printf("rot_a: %d, rot_b: %d, steps: %d\n", current->move.rot_a, current->move.rot_b, current->move.steps);
        printf("distance_w_rot: %d\n", distance_w_rot(current));
        printf("distance_w_rev_rot: %d\n", distance_w_rev_rot(current));
        current = current->next;
    }
    printf("\n");
}
void print_list_b(t_stack_node *head)
{
    if (!head)
        return;

    t_stack_node *current = head;
    printf("\nB: %d ", current->value);
    printf("rot_a: %d, rot_b: %d, steps: %d\n", current->move.rot_a, current->move.rot_b, current->move.steps);
    printf("distance_w_rot: %d\n", distance_w_rot(current));
    printf("distance_w_rev_rot: %d\n", distance_w_rev_rot(current));
    current = current->next;
    while (current != head)
    {
        printf("%d ", current->value);
        printf("rot_a: %d, rot_b: %d, steps: %d\n", current->move.rot_a, current->move.rot_b, current->move.steps);
    printf("distance_w_rot: %d\n", distance_w_rot(current));
    printf("distance_w_rev_rot: %d\n", distance_w_rev_rot(current));
        current = current->next;
    }
    printf("\n");
}

int main(int ac, char **av)
{
    t_stack_node *a;
    t_stack_node *b;

    a = NULL;
    b = NULL;
    if (ac == 1)
        return (0);
    if (validate_args(ac, av))
        return (1);
    if (process_args(ac, av, &a))
        return (1);

    
   

    // if (stack_len(a) == 3 && !is_a_ordered(a))
    //     sort_three(&a);
    // else
    //     turk(&a);
   
   

    


    // printf("is a ordered: %d\n", is_a_ordered(a));
    // printf("is a sorted: %d\n", is_a_ascen(a));
    print_list(a);
    optimal_rotations(a, b);
    print_list(a);
    pb(&a, &b);
    pb(&a, &b);

    print_list(a);
    print_list_b(b);

    // Test optimal_rotations
    optimal_rotations(a, b);
    print_list(a);
    print_list_b(b);
    
    


    
    
    stack_free(&a);
    stack_free(&b);
    return (0);
    
}