#include "push_swap.h"

void print_list(t_stack_node *head)
{
    t_stack_node *current = head;
    if (!head)
        return;
    do
    {
        printf("%d ", current->value);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main(int ac, char **av)
{
    t_stack_node *a;
    //t_stack_node *b;

    a = NULL;
   // b = NULL;
    if (ac == 1)
        return (0);
    if (validate_args(ac, av))
        return (1);
    if (process_args(ac, av, &a))
        return (1);
    print_list(a);
    stack_free(&a);
    return (0);
    
}