#ifndef PUSH_SWAP
# define PUSH_SWAP


#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Libft/libft.h"
#include "ft_Printf/ft_printf.h"


typedef struct s_move {
    int rot_a; // Rotation count for stack A
    int rot_b; // Rotation count for stack B
    int steps; // Total steps required
} t_move;

typedef struct s_stack_node
{
    int					value;
    struct s_stack_node	*next;
    struct s_stack_node	*prev;  
    bool				head;
    t_move				move;
}   t_stack_node;

int	ft_strcmp(char *s1, char *s2);
int validate_args(int ac, char **av);
int is_space(char c);
void free_split_av(char **split_av);
t_stack_node *stack_init(t_stack_node **stack, char **av);
int error_syntax(char *str);
int error_dups(t_stack_node *a, int value);
void stack_free(t_stack_node **stack);
void free_errors(t_stack_node **a, char **av);
int process_args(int ac, char **av, t_stack_node **a);
char *fill_all_args(int ac, char **av);
long	ft_atol(const char *str);
void sa(t_stack_node **a);
void sb(t_stack_node **b);
void ss(t_stack_node **a,t_stack_node **b);
void ra(t_stack_node **a);
void rb(t_stack_node **b);
void rr(t_stack_node **a, t_stack_node **b);











#endif