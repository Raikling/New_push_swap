#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

char *fill_all_args(int ac, char **av);

int validate_args(int ac, char **av)
{
	int i;
	char *args;

	i = 0;
	while (i < ac)
	{
		args = av[i];
		while (args && is_space(*args))
			args++;
		if (*args == '\0')
		{
			write (2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

int check_syntax(char **split_av, char *all_args)
{
    int i;
	
	i = 0;
    while (split_av[i])
    {
        if (error_syntax(split_av[i]))
            return (free(all_args), free_split_av(split_av), write(2, "Error\n", 6), 1);
        i++;
    }
    return (0);
}

int check_duplicates(t_stack_node **a, char *all_args, char **split_av)
{
    t_stack_node *current;
	
	current = *a;
    while (current)
    {
        if (error_dups(*a, current->value))
            return (free(all_args), free_split_av(split_av), stack_free(a), write(2, "Error\n", 6), 1);
        current = current->next;
        if (current == *a)
            break;
    }
    return 0;
}

int process_args(int ac, char **av, t_stack_node **a)
{
    char *all_args = fill_all_args(ac, av);
    char **split_av = ft_split(all_args, ' ');

    if (check_syntax(split_av, all_args))
        return 1;
    if (stack_init(a, split_av) == NULL)
        return (free(all_args), free_split_av(split_av), 1);
    if (check_duplicates(a, all_args, split_av))
        return 1;

    free_split_av(split_av);
    free(all_args);
    if (!*a)
        return (write(2, "Error\n", 6), 1);
    return 0;
}


char *fill_all_args(int ac, char **av)
{
    int i;
    char *all_args;
    char *tmp;

    all_args = ft_strdup(av[1]);
    i = 2;
    while (i < ac)
    {
        tmp = ft_strjoin(all_args, " ");
        free(all_args);
        all_args = ft_strjoin(tmp, av[i]);
        free(tmp);
        i++;
    }
    return all_args;
}
