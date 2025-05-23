#include "../cub3d.h"

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

int	get_map(t_map *map)
{
	char	*str;
	char	*map_temp;
	int		fd;

	fd = open("./maps/edge.cub", O_RDONLY);
	if (fd == -1)
		return (printf("error reading the map\n"), 1);
	str = get_next_line(fd);
	map_temp = NULL;
	map->rows = 0;
	while (str)
	{
		map_temp = ft_straddstr(map_temp, str);
		map->rows++;
		free(str);
		str = get_next_line(fd);
	}
	map->data = ft_split(map_temp, "\n");
	free(map_temp);
	for (int i = 0; i < map->rows; i++)
		printf("%s\n", map->data[i]);
	return (0);
}
