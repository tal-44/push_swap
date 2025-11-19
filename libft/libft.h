#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/* String functions */
int		ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int c);

/* Memory functions */
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

/* Print functions */
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

#endif
