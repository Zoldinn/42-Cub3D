#include "../cub3d.h"

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
	printf("*********************\n");
}

void	find_start_map(t_map *map, int *i, char **temp)
{
	char	**arr;

	while (*i >= 0)
	{
		arr = ft_split(temp[*i], " \t\n");
		if (arr[0])
		{
			if (ft_strlen(arr[0]) < 3 && (ft_strchr(temp[*i], '/') != NULL
					|| ft_strchr(temp[*i], ',') != NULL))
			{
				free_arr(arr);
				break ;
			}
		}
		free_arr(arr);
		(*i)--;
	}
	map->start_map = *i;
}

void	find_end_map(t_map *map, int *i, char **temp)
{
	int		j;

	j = 0;
	(*i)++;
	while (temp[*i])
	{
		if (temp[*i][0] == '\n')
			break ;
		map->map[j++] = ft_strdup(temp[*i]);
		map->rows++;
		(*i)++;
	}
}

void	compare_maps(t_map *map, char *file_temp, int i)
{
	char	*temp;
	int		j;
	int		index_map;

	index_map = 0;
	while (map->map[index_map])
	{
		j = 0;
		while (file_temp[i] != '\n')
		{
			j++;
			i--;
		}
		temp = ft_substr(file_temp, i + 1, j);
		printf("map : %s\n", map->map[index_map]);
		printf("temp : %s\n", temp);
		if (ft_cmpstr(map->map[index_map], temp) != 0)
		{
			free(temp);
			printf("Error\nEmpty lines are not allowed in the map\n");
			free_and_exit(map, 1);
		}
		free(temp);
		index_map++;
	}
}

void	check_empty_lines_map(t_map *map, char *file_temp)
{
	int		i;
	int		j;

	i = ft_strlen(file_temp) - 1;
	j = 0;
	while (j < map->rows && i >= 0)
	{
		if (file_temp[i] == '\n')
			j++;
		i--;
	}
	if (j != map->rows)
	{
		printf("Error\nEmpty lines are not allowed in the map\n");
		free_and_exit(map, 1);
	}
	compare_maps(map, file_temp, i);
}
