#include "../cub3d.h"

//check if the map is valid
//x is set to know if we check '0' or not
int	check_map_map(t_map *map, int i, int j, int x)
{
	if (x == 1)
	{
		if (map->map[i][j] == '0' || map->map[i][j] == '1'
		|| map->map[i][j] == 'N' || map->map[i][j] == 'S'
		|| map->map[i][j] == 'E' || map->map[i][j] == 'W'
		|| map->map[i][j] == ' ')
			return (0);
		else
			return (printf("'%c' is not valid\n", map->map[i][j]), 1);
	}
	else
	{
		if ((i < 0 || i == map->rows) || ((i + 1) == map->rows
				&& map->map[i][j] == ' ') || j < 0 || map->map[i][j] == '\0')
			return (printf("The borders of the map are not valid\n"), 1);
		else if (map->map[i][j] == '0' || map->map[i][j] == '1'
			|| map->map[i][j] == 'N' || map->map[i][j] == 'S'
			|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
			return (0);
		else if (map->map[i][j] == ' ')
			return (printf("'%c' not valid next to '0'\n", map->map[i][j]), 1);
		else
			return (printf("'%c' is not valid\n", map->map[i][j]), 1);
	}
}

void	get_check_map_map(t_map *map, int i, int j)
{
	if (map->map[i][j] != '0')
	{
		if (check_map_map(map, i, j, 1) == 1)
			free_and_exit(map);
	}
	else
	{
		if (check_map_map(map, i + 1, j, 0) == 1)
			free_and_exit(map);
		if (check_map_map(map, i - 1, j, 0) == 1)
			free_and_exit(map);
		if (check_map_map(map, i, j + 1, 0) == 1)
			free_and_exit(map);
		if (check_map_map(map, i, j - 1, 0) == 1)
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
		while (map->map[i][j])
		{
			get_check_map_map(map, i, j);
			j++;
		}
		i++;
	}
}

void	find_start_map(t_map *map, int index, char **temp)
{
	char	**arr;
	int		i;

	index--;
	while (index-- != 0)
	{
		printf("index : %d\n", index);
		printf("%s\n", temp[index]);
		arr = ft_split(temp[index], " ");
		if (ft_strlen(arr[0]) < 3)
			break;
		free_db_array(arr);
	}
	free_db_array(arr);
	map->start_map = index;
	map->map = malloc((arrlen(temp) - index + 1) * sizeof(char *));
	map->data = malloc((index + 1) * sizeof(char *));
	while (temp[index])
	{
		map->map[index] = ft_strdup(temp[index]);
		index++;
	}
	map->map[index] = NULL;
	i = 0;
	while (i < map->start_map)
	{
		map->data[i] = ft_strdup(temp[i]);
		i++;
	}
	map->data[i] = NULL;
	free(temp);
}

//read map in .cub format, put it in a char** and check if map is correct
int	get_map(t_map *map)
{
	char	**temp;
	char	*str;
	char	*file_temp;
	int		fd;
	int		index;

	fd = open("./maps/default.cub", O_RDONLY);
	if (fd == -1)
		return (printf("error reading the file\n"), 1);
	str = get_next_line(fd);
	file_temp = NULL;
	index = 0;
	// map->rows = 0;
	while (str)
	{
		index++;
		file_temp = ft_straddstr(file_temp, str);
		// map->rows++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	temp = ft_split(file_temp, "\n");
	find_start_map(map, index, temp);
	index = 0;
	while (map->data[index])
	{
		printf("%s\n", map->data[index]);
		index++;
	}
	printf("\n");
	index = 0;
	while (map->map[index])
	{
		printf("%s\n", map->map[index]);
		index++;
	}
	// map->map = ft_split(map_temp, "\n");
	// free(map_temp);
	// check_map(map);
	return (0);
}
