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
void rra(t_stack_node **a);
void rrb(t_stack_node **b);
void rrr(t_stack_node **a, t_stack_node **b);
void pa(t_stack_node **a, t_stack_node **b);
void pb(t_stack_node **a, t_stack_node **b);
int	stack_len(t_stack_node *stack);
int	is_a_ordered(t_stack_node *a);
t_stack_node	*min_node_in_stack(t_stack_node *stack);
t_stack_node	*max_node_in_stack(t_stack_node *stack);
void sort_three(t_stack_node **stack);
void	turk(t_stack_node **a, t_stack_node **b);
int	is_a_sorted(t_stack_node *a);
int	is_b_sorted(t_stack_node *b);
int	distance_w_rot(t_stack_node *node);
int	distance_w_rev_rot(t_stack_node *node);
void	finalize_a(t_stack_node **a);
void	push_from_a_to_b(t_stack_node **a, t_stack_node **b);
void	optimal_move(t_stack_node *a, t_stack_node *b);
void	emptying_b(t_stack_node **a, t_stack_node **b);


















#endif