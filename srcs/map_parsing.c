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
			free_and_exit(map, 1);
	}
	else
	{
		if (check_map_map(map, i + 1, j, 0) == 1)
			free_and_exit(map, 1);
		if (check_map_map(map, i - 1, j, 0) == 1)
			free_and_exit(map, 1);
		if (check_map_map(map, i, j + 1, 0) == 1)
			free_and_exit(map, 1);
		if (check_map_map(map, i, j - 1, 0) == 1)
			free_and_exit(map, 1);
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

//get map and datas from file and put it in map structure
void	find_start_map(t_map *map, char **temp, int i)
{
	char	**arr;
	int		j;

	while (i != 0)
	{
		arr = ft_split(temp[i], " \n");
		if (ft_strlen(arr[0]) < 3)
			break ;
		free_db_array(arr);
		i--;
	}
	free_db_array(arr);
	map->start_map = i;
	map->map = ft_calloc((arrlen(temp) - i + 1), sizeof(char *));
	map->data = ft_calloc((map->start_map + 2), sizeof(char *));
	j = 0;
	while (temp[++i])
	{
		map->map[j++] = ft_strdup(temp[i]);
		map->rows++;
	}
	i = -1;
	j = -1;
	while (i++ < map->start_map)
		map->data[++j] = ft_strdup(temp[i]);
}

void	print_datas_and_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->data[i])
	{
		printf("%s\n", map->data[i]);
		i++;
	}
	printf("------------------------------\n");
	i = 0;
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		i++;
	}
}

//read map and datas from file
int	get_map(t_map *map)
{
	char	**temp;
	char	*str;
	char	*file_temp;
	int		fd;

	fd = open("./maps/default.cub", O_RDONLY);
	if (fd == -1)
		return (printf("error reading the file\n"), 1);
	str = get_next_line(fd);
	file_temp = NULL;
	map->rows = 0;
	while (str)
	{
		file_temp = ft_straddstr(file_temp, str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	temp = ft_split(file_temp, "\n");
	find_start_map(map, temp, arrlen(temp) - 1);
	free_db_array(temp);
	free(file_temp);
	print_datas_and_map(map);
	check_map(map);
	return (0);
}
