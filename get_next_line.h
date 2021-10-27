#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

void	*ft_memmove(void *dst, void *src, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *temp_str, char *buf);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);

#endif