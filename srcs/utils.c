#include "../cub3d.h"

//add s2 after s1 
//and free(s1)
//(kind of realloc)
char	*ft_straddstr(char *s1, char *s2)
{
	char	*res;

	if (s1 == NULL)
	{
		if (s2 == NULL)
			return (NULL);
		res = ft_strdup(s2);
		return (res);
	}
	else
	{
		res = ft_strjoin(s1, s2);
		free(s1);
		return (res);
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[1000];
	static int	index_buf = 0;
	static int	bytes_read = 0;
	char		line[1000];
	int			index_line;

	index_line = 0;
	while (1)
	{
		if (index_buf >= bytes_read)
		{
			index_buf = 0;
			bytes_read = read(fd, buffer, 1000);
			if (bytes_read <= 0)
				break ;
		}
		line[index_line++] = buffer[index_buf++];
		if (line[index_line - 1] == '\n')
			break ;
	}
	line[index_line] = '\0';
	if (bytes_read < 0 || index_line == 0)
		return (NULL);
	return (ft_strdup(line));
}
