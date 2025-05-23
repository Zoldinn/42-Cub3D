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

//check if the map data is valid
//x is set to know if we check map border
int	check_map_data(t_map *map, int i, int j, int x)
{
	if ((i < 0 || i == map->rows)
		|| j < 0 || map->data[i][j] == '\0')
		return (1);
	if (x == 1)
	{
		if (map->data[i][j] == '0' || map->data[i][j] == '1'
		|| map->data[i][j] == 'N' || map->data[i][j] == 'S'
		|| map->data[i][j] == 'E' || map->data[i][j] == 'W'
		|| map->data[i][j] == ' ')
			return (0);
	}
	else
	{
		if (map->data[i][j] == '0' || map->data[i][j] == '1'
		|| map->data[i][j] == 'N' || map->data[i][j] == 'S'
		|| map->data[i][j] == 'E' || map->data[i][j] == 'W')
			return (0);
	}
	return (printf("char : %c\n", map->data[i][j]), 1);
}

int	get_check_map_data(t_map *map, int i, int j)
{
	if (map->data[i][j] != '0')
	{
		if (check_map_data(map, i, j, 1) == 1)
			return (1);
	}
	else
	{
		if (check_map_data(map, i + 1, j, 0) == 1)
			return (1);
		if (check_map_data(map, i - 1, j, 0) == 1)
			return (1);
		if (check_map_data(map, i, j + 1, 0) == 1)
			return (1);
		if (check_map_data(map, i, j - 1, 0) == 1)
			return (1);
	}
	return (0);
}

int	check_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (map->data[i][j])
		{
			if (get_check_map_data(map, i, j) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//read map in .cub format, put it in a char** and check if map is correct
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
	map->data = ft_split(map_temp, '\n');
	free(map_temp);
	if (check_map(map) == 1)
		printf("Error 1 in the map\n");
	return (0);
}
