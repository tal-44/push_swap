#include "../../includes/push_swap.h"

static void	sort_two(t_stack **stack_a)
{    
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

// we look for the biggest value and then we rotate or reverse the other two numbers if needed
static void	sort_three(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack_a;
	second = first->next;
	third = second->next;
	if (first->value > second->value && first->value > third->value)
	{
		ra(stack_a);
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	else if (second->value > first->value && second->value > third->value)
	{
		rra(stack_a);
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	else
	{
		if (first->value > second->value)
			sa(stack_a);
	}
}

// we locate the smallest value and then we sort the remaining three numbers
static void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min_pos;

	min_pos = find_min_pos(*stack_a);
	if (min_pos <= 1)
		while (min_pos-- > 0)
			ra(stack_a);
	else
		while (min_pos++ < 4)
			rra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		min_pos;

	min_pos = find_min_pos(*stack_a);
	if (min_pos <= 2)
		while (min_pos-- > 0)
			ra(stack_a);
	else
		while (min_pos++ < 5)
			rra(stack_a);
	pb(stack_a, stack_b);
	min_pos = find_min_pos(*stack_a);
	if (min_pos <= 1)
		while (min_pos-- > 0)
			ra(stack_a);
	else
		while (min_pos++ < 4)
			rra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	forced_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}
