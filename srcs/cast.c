#include "../includes/push_swap.h"


void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	count_words(char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**split;

	i = 0;
	count = 0;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (-1);
		j = 0;
		while (split[j])
		{
			count++;
			j++;
		}
		free_split(split);
		i++;
	}
	return (count);
}

static char	**fill_result(char **result, char **argv)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (NULL);
		j = 0;
		while (split[j])
		{
			result[k] = split[j];
			k++;
			j++;
		}
		free(split);
		i++;
	}
	result[k] = NULL;
	return (result);
}

char	**cast(char **argv)
{
	char	**result;
	int		total_words;

	total_words = count_words(argv);
	if (total_words <= 0)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (total_words + 1));
	if (!result)
		return (NULL);
	result = fill_result(result, argv);
	if (!result)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
