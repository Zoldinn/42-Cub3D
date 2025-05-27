#include "../cub3d.h"

void	free_map(t_map *map)
{
	free_db_array(map->data);
	free_db_array(map->map);
}

void	free_and_exit(t_map *map, int code)
{
	free_map(map);
	exit(code);
}

void	free_db_array(char **arr)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}
