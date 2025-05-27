#include "../cub3d.h"

void	free_map(t_map *map)
{
	free_arr(map->data);
	free_arr(map->map);
	free_arr(map->txt);
}

void	free_and_exit(t_map *map, int code)
{
	free_map(map);
	exit(code);
}

void	free_arr(char **arr)
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
