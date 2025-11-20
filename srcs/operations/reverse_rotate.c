#include "../includes/push_swap.h"

// puts the last element at the top of the stack
static void	reverse_rotate(t_stack **stack)
{
    t_stack *tail;
    t_stack *before_tail;

    if (!*stack || !(*stack)->next)
        return ;
    tail = stack_last(*stack);
    before_tail = *stack;
    while (before_tail->next != tail)
        before_tail = before_tail->next;
    before_tail->next = NULL;
    tail->next = *stack;
    *stack = tail;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
