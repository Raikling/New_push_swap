#include "push_swap.h"

void print_list(t_stack_node *head)
{
    if (!head)
        return;

    t_stack_node *current = head;
    printf("A: %d ", current->value);
    current = current->next;
    while (current != head)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
void print_list_b(t_stack_node *head)
{
    if (!head)
        return;

    t_stack_node *current = head;
    printf("B: %d ", current->value);
    current = current->next;
    while (current != head)
    {
        printf("%d ", current->value);
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
   
   

    


    printf("is a ordered: %d\n", is_a_ordered(a));
    printf("is a sorted: %d\n", is_a_ascen(a));
    print_list(a);

    int distance = distance_w_rot(a);
    printf("distance_w_rot: %d\n", distance);

    // Move to a different node and test again
    a = a->next->next; // Move to the node with value -2
    distance = distance_w_rot(a);
    printf("distance_w_rot from node -2: %d\n", distance);
    
    stack_free(&a);
    stack_free(&b);
    return (0);
    
}