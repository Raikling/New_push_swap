#include "push_swap.h"

int error_syntax(char *str)
{
    if (str == NULL || *str == '\0')
        return (1);
    while (*str && is_space(*str))
        str++;
    if (*str == '\0')
        return (1);
    if (!(*str == '+' || *str == '-' || ft_isdigit(*str)))
        return (1);
    if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
        return (1);
    while (*++str)
    {
        if (!ft_isdigit(*str) && !is_space(*str))
            return (1);
    }
    return (0);
}

int error_dups(t_stack_node *a, int value)
{
    
    t_stack_node *current;
    int count;

    current = a;
    count = 0;
    if (!a)
        return (0);
    while (current != a || count == 0)
    {
        if (current->value == value)
            count++;
        current = current->next;
    }
    return (count >= 2);
}

void stack_free(t_stack_node **stack)
{
    t_stack_node *tmp;
    t_stack_node *current;

    if (!stack || !*stack)
        return;
    current = *stack;
    while (current)
    {
        tmp = current->next;
        free(current);
        if (tmp == *stack)
            break;
        current = tmp;
    }
    *stack = NULL;
}

void free_errors(t_stack_node **a, char **av)
{
    stack_free(a);
    free_split_av(av);
    write(2, "Error\n", 6);
}
void free_split_av(char **split_av)
{
    int i;

    i = 0;
    while (split_av[i])
    {
        free(split_av[i]);
        i++;
    }
    free(split_av);
}