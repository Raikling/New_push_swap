#include "push_swap.h"

t_stack_node *create_node(int value)
{
    t_stack_node *new_node;

    new_node = malloc(sizeof(t_stack_node));
    if (new_node == NULL)
        return (NULL);
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->head = false;
    new_node->move.rot_a = 0;
    new_node->move.rot_b = 0;
    new_node->move.steps = 0;
    return (new_node);
}

t_stack_node *initialize_stack_head(t_stack_node **stack, char **av)
{
    long value;
    t_stack_node *stack_head;

    if (!av || !av[0])
        return (NULL);

    value = ft_atol(av[0]);
    if (value > INT_MAX || value < INT_MIN)
    {
        write(2, "Error\n", 6);
        return (NULL);
    }

    stack_head = create_node(value);
    if (stack_head == NULL)
        return (NULL);

    stack_head->head = true;
    stack_head->prev = stack_head;
    stack_head->next = stack_head;
    *stack = stack_head;

    return (stack_head);
}

t_stack_node *populate_stack(t_stack_node *stack_head, char **av)
{
    int i = 1;
    long value;
    t_stack_node *node_prev = stack_head;

    while (av[i])
    {
        value = ft_atol(av[i]);
        if (value > INT_MAX || value < INT_MIN)
            return(stack_free(&stack_head), write(2, "Error\n", 6), NULL);
        node_prev->next = create_node(value);
        if (node_prev->next == NULL)
            return (stack_free(&stack_head), NULL);
        node_prev->next->next = stack_head;
        node_prev->next->prev = node_prev;
        node_prev = node_prev->next;
        node_prev->head = false;
        stack_head->prev = node_prev;
        i++;
    }
    return (stack_head);
}

t_stack_node *stack_init(t_stack_node **stack, char **av)
{
    t_stack_node *stack_head;

    stack_head = initialize_stack_head(stack, av);
    if (stack_head == NULL)
        return (NULL);

    if (populate_stack(stack_head, av) == NULL)
        return (NULL);

    return (stack_head);
}



// t_stack_node *stack_init(t_stack_node **stack, char **av)
// {
//     int i;
//     t_stack_node *stack_head;
//     t_stack_node *node_prev;
//     long value;


//     if (!av || !av[0])
//         return (NULL);
//     value = ft_atol(av[0]);
//     if (value > INT_MAX || value < INT_MIN)
//         return (stack_free(&stack_head), write(2, "Error\n", 6), NULL);
//     stack_head = create_node(value);
//     if (stack_head == NULL)
//         return (stack_free(&stack_head), NULL);
//     stack_head->head = true;
//     stack_head->prev = stack_head;
//     stack_head->next = stack_head;
//     *stack = stack_head;
//     i = 1; 
//     node_prev = stack_head;
//     while (av[i])
//     {
//         value = ft_atol(av[i]);
//         if (value > INT_MAX || value < INT_MIN)
//             return (stack_free(&stack_head), write(2, "Error\n", 6), NULL);
//         node_prev->next = create_node(value);
//         if (node_prev->next == NULL)
//             return (stack_free(&stack_head), NULL);
//         node_prev->next->next = stack_head; 
//         node_prev->next->prev = node_prev;  
//         node_prev = node_prev->next; 
//         node_prev->head = false;
//         i++;
//         stack_head->prev = node_prev;
//     }
//     return (stack_head);
// }

