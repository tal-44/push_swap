#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	char	**numbers;

	if (argc < 2)
		return (0);
	numbers = cast(argv + 1);
	if (!numbers || !is_valid_input(numbers))
	{
		write(2, "Error\n", 6);
		if (numbers)
			free_split(numbers);
		return (1);
	}
	if (!push_swap(numbers))
	{
		write(2, "Error\n", 6);
		free_split(numbers);
		return (1);
	}
	free_split(numbers);
	return (0);
}
