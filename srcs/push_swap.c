#include "../includes/push_swap.h"

int	build_stacks(t_stack **stack_a, t_stack **stack_b, char **numbers)
{
	int		i;
	t_stack	*new_node;

	*stack_a = NULL;
	*stack_b = NULL;
	i = 0;
	while (numbers[i])
	{
		new_node = stack_new(ft_atoi(numbers[i]));
		if (!new_node)
		{
			free_stack(stack_a);
			return (0);
		}
		stack_add_back(stack_a, new_node);
		i++;
	}
	return (1);
}

int	push_swap(char **numbers)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!build_stacks(&stack_a, &stack_b, numbers))
		return (0);
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (1);
	}
	if (stack_size(stack_a) <= 5)
		forced_sort(&stack_a, &stack_b, stack_size(stack_a));
	else
		sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (1);
}
