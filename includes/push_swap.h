#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

//	value:	The number stored in this stack node
//	index:	The position of this number in an ideally sorted stack (0 = smallest)
//			in a stack: [6, 2, 9] -> indexes [1, 0, 2]
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

// swap the first 2 elements
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

// Move element from one stack to another
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

// Rotate upwards (first -> last)
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

// Rotate downwards (last -> first)
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);


t_stack	*stack_new(int value); 
void	stack_add_back(t_stack **stack, t_stack *new);
void	free_stack(t_stack **stack);

int		stack_size(t_stack *stack); 
t_stack	*stack_last(t_stack *stack);
int		find_min_pos(t_stack *stack);
int		is_sorted(t_stack *stack);

int		is_valid_input(char **av); 
char	**cast(char **argv);
void	free_split(char **split);
int		push_swap(char **numbers);

void	forced_sort(t_stack **stack_a, t_stack **stack_b, int size);
void	sort(t_stack **stack_a, t_stack **stack_b);
void	create_index(t_stack **stack);

#endif
