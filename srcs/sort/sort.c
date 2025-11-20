
#include "../../includes/push_swap.h"

// Sort stack_a using stack_b as auxiliary stack
// For each bit position (from right to left):
//   - If the bit of the index is 0 → move to stack_b (pb)
//   - If the bit of the index is 1 → rotate in stack_a (ra)
// After that, move everything from stack_b back to stack_a (pa)
// Repeat for the next bit
// Example: index = 5 (binary: 101)
//   bit 0: (5 >> 0) & 1 = 101 & 1 = 1 → ra
//   bit 1: (5 >> 1) & 1 = 010 & 1 = 0 → pb
//   bit 2: (5 >> 2) & 1 = 001 & 1 = 1 → ra
void    sort(t_stack **stack_a, t_stack **stack_b)
{
    int max_bits;
    int size;
    int byte_pos;
    int i;

    create_index(stack_a);
    size = stack_size(*stack_a);
    max_bits = 0;
    while ((size - 1) >> max_bits)
        max_bits++;
    byte_pos = 0;
    while (byte_pos < max_bits)
    {
        i = 0;
        while (i < size)
        {
            if ((((*stack_a)->index >> byte_pos) & 1) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
            i++;
        }
        while (*stack_b)
            pa(stack_a, stack_b);
        byte_pos++;
    }
}