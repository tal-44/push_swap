#include "../../includes/push_swap.h"

// find the position of the smallest value in the stack
int	find_min_pos(t_stack *stack)
{
	int	min_val;
	int	min_pos;
	int	i;

	min_val = stack->value;
	min_pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min_pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_pos);
}

int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

// Assigns an index to each element in the stack
void	create_index(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;
	int		index;

	current = *stack;
	while (current)
	{
		index = 0;
		tmp = *stack;
		while (tmp)
		{
			if (tmp->value < current->value)
				index++;
			tmp = tmp->next;
		}
		current->index = index;
		current = current->next;
	}
}
