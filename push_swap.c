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
    t_stack_node *a = NULL;
    t_stack_node *b = NULL;
    if (ac == 1 || validate_args(ac, av) || process_args(ac, av, &a))
        return (1);

    // print_list(a);
    if (stack_len(a) == 3)
        sort_three(&a);
    else 
        turk(&a, &b);
    // print_list(a);

    stack_free(&a);
    stack_free(&b);
    return (0);
}

