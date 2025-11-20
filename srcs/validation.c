#include "../includes/push_swap.h"

int	has_duplicates(char **numbers)
{
    int		i;
    int		j;

    i = 0;
    while (numbers[i])
    {
        j = i + 1;
        while (numbers[j])
        {
            if (ft_atoi(numbers[i]) == ft_atoi(numbers[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}


static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

// I use int_min because 2147483648 is out of int range
static int	is_int_range(char *str)
{
	long long	num;
	long long	int_min;
	int			i;
	int			sign;

	int_min = 2147483648LL;
	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > 2147483647) || (sign == -1 && num > int_min))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_input(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (!is_number(array[i]) || !is_int_range(array[i]))
			return (0);
		i++;
	}
	if (has_duplicates(array))
		return (0);
	return (1);
}
