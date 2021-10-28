#include "get_next_line_bonus.h"
#include <stdio.h>
static char	*ft_read(int fd, char *temp_str);

static char	*ft_get_line(char *temp_str);

static char	*ft_clean_str(char *temp_str);

char	*get_next_line(int fd)
{
	static char	*temp_str;
	char		*next_line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	temp_str = ft_read(fd, temp_str);
	if (!temp_str)
		return (0);
	next_line = ft_get_line(temp_str);
	temp_str = ft_clean_str(temp_str);
	return (next_line);
}

static char	*ft_read(int fd, char *temp_str)
{
	char	*buf;
	int		read_return;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	read_return = 1;
	while (!ft_strchr(temp_str, '\n') && read_return != 0)
	{
		read_return = read(fd, buf, BUFFER_SIZE);
		if (read_return == -1)
		{
			free(buf);
			return (0);
		}
		buf[read_return] = '\0';
		if (!temp_str)
			temp_str = ft_strdup(buf);
		else
			temp_str = ft_strjoin(temp_str, buf);
	}
	free(buf);
	return (temp_str);
}

static char	*ft_get_line(char *temp_str)
{
	char	*str;
	int		i;

	i = 0;
	if (!temp_str[i])
		return (0);
	while (temp_str[i] != '\0' && temp_str[i] != '\n')
		i++;
	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (temp_str[i] != '\0' && temp_str[i] != '\n')
	{
		str[i] = temp_str[i];
		i++;
	}
	if (temp_str[i] == '\n')
	{
		str[i] = temp_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_clean_str(char *temp_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (temp_str[i] != '\0' && temp_str[i] != '\n')
		i++;
	if (temp_str[i] == '\0')
	{
		free(temp_str);
		return (0);
	}
	str = malloc((ft_strlen(temp_str) - i + 1) * sizeof(char));
	if (!str)
		return (0);
	i++;
	j = 0;
	while (temp_str[i] != '\0')
		str[j++] = temp_str[i++];
	str[j] = '\0';
	free(temp_str);
	return (str);
}
