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
//x is set to know if we check '0' or not
int	check_map_data(t_map *map, int i, int j, int x)
{
	if (x == 1)
	{
		if (map->data[i][j] == '0' || map->data[i][j] == '1'
		|| map->data[i][j] == 'N' || map->data[i][j] == 'S'
		|| map->data[i][j] == 'E' || map->data[i][j] == 'W'
		|| map->data[i][j] == ' ')
			return (0);
		else
			return (printf("'%c' is not valid\n", map->data[i][j]), 1);
	}
	else
	{
		if ((i < 0 || i == map->rows) || ((i + 1) == map->rows
				&& map->data[i][j] == ' ') || j < 0 || map->data[i][j] == '\0')
			return (printf("The borders of the map are not valid\n"), 1);
		else if (map->data[i][j] == '0' || map->data[i][j] == '1'
			|| map->data[i][j] == 'N' || map->data[i][j] == 'S'
			|| map->data[i][j] == 'E' || map->data[i][j] == 'W')
			return (0);
		else if (map->data[i][j] == ' ')
			return (printf("'%c' not valid next to '0'\n", map->data[i][j]), 1);
		else
			return (printf("'%c' is not valid\n", map->data[i][j]), 1);
	}
}

void	get_check_map_data(t_map *map, int i, int j)
{
	if (map->data[i][j] != '0')
	{
		if (check_map_data(map, i, j, 1) == 1)
			free_and_exit(map);
	}
	else
	{
		if (check_map_data(map, i + 1, j, 0) == 1)
			free_and_exit(map);
		if (check_map_data(map, i - 1, j, 0) == 1)
			free_and_exit(map);
		if (check_map_data(map, i, j + 1, 0) == 1)
			free_and_exit(map);
		if (check_map_data(map, i, j - 1, 0) == 1)
			free_and_exit(map);
	}
}

void	check_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (map->data[i][j])
		{
			get_check_map_data(map, i, j);
			j++;
		}
		i++;
	}
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
	map->data = ft_split(map_temp, "\n");
	free(map_temp);
	check_map(map);
	return (0);
}
