#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* Stack operations */
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* Stack utils */
t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
void	free_stack(t_stack **stack);

/* Input validation */
int		is_valid_input(char **av);
int		has_duplicates(t_stack *stack);
void	error_exit(t_stack **stack_a, t_stack **stack_b);

/* Sorting */
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);
int		is_sorted(t_stack *stack);

#endif
