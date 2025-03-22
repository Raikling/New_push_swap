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

t_stack_node *stack_init(t_stack_node **stack, char **av)
{
    int i;
    t_stack_node *stack_head;
    t_stack_node *node_prev;

    if (!av || !av[0])
        return (NULL);

    stack_head = create_node(ft_atol(av[0]));
    if (stack_head == NULL)
    {
        stack_free(&stack_head);
        return (NULL);
    }
    stack_head->head = true;
    stack_head->prev = stack_head;
    stack_head->next = stack_head;
    *stack = stack_head;

    i = 1; 
    node_prev = stack_head;
    while (av[i])
    {
        node_prev->next = create_node(ft_atol(av[i])); //10
        if (node_prev->next == NULL)
        {
            stack_free(&stack_head);
            return (NULL);
        }
        node_prev->next->next = stack_head; //10->next = 27
        node_prev->next->prev = node_prev; //10->prev = 27
        node_prev = node_prev->next; //node_prev = 10
        node_prev->head = false; //10->head = false
        i++;
        stack_head->prev = node_prev;   //27->prev = 10
    }
    return (stack_head);
}

