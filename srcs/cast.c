#include "../includes/push_swap.h"

char    *cast(int argc, char **argv)
{
    char    **result;
    int     i;
    
    if (argc == 1)
        return (argv[0]);
    i = 0;
    while (i < argc)
    {
        result[i] = argv[i];
        i++;
    }
    result[i] = (NULL);
    return (result);        
}