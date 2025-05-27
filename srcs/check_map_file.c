#include "../cub3d.h"

int	check_rgb_values(char *rgb[2])
{
	int		i;
	char	**values;
	int		j;
	int		value;

	i = -1;
	while (++i < 2)
	{
		values = ft_split(rgb[i], ",");
		if (!values)
			return (p_er("Failed split rgb values"), 1);
		j = -1;
		while (values[++j] && j < 3)
		{
			value = ft_check_atoi(values[j]);
			if (value < 0 || value > 255)
				return (p_er("RGB values should be int [0;255]"), 1);
		}
		if (j != 3)
			return (p_er("RGB values are only 3 int"), 1);
	}
	return (0);
}

int	get_data(t_map *map, char **id, int i)
{
	int		j;
	char	**line;

	while (map->data[++i])
	{
		line = ft_split(map->data[i], " \n\t\0");
		if (!line)
			return (1);
		j = -1;
		while (id[++j])
		{
			if (ft_cmpstr(line[0], id[j]) == 0)
			{
				if (map->txt[j] == NULL)
					map->txt[j] = ft_straddstr(map->txt[j], line[1]);
				else
					return (p_er("there's already this texture"), 1);
				break ;
			}
		}
		if (ft_cmpstr(line[0], id[j]) != 0)
			return (p_er("there's something not required"), 1);
	}
	free_db_array(id);
	return (0);
}

char	**id(void)
{
	char	**id;

	id = ft_calloc(sizeof(char *), 7);
	if (!id)
		return (NULL);
	id[NO] = "NO";
	id[SO] = "SO";
	id[WE] = "WE";
	id[EA] = "EA";
	id[F] = "F";
	id[C] = "C";
	return (id);
}

int	check_file(char *path, t_map *map)
{
	int		i;
	int		count;
	char	*rgb[2];

	if (get_map(map, path) != 0)
		return (1);
	map->txt = ft_calloc(sizeof(char *), 7);
	i = -1;
	while (map->txt[++i])
		map->txt[i] = NULL;
	if (get_data(map, id(), -1) != 0)
		return (1);
	i = -1;
	count = 0;
	while (map->txt[++i])
		count++;
	if (count != 6)
		return (p_er("there's missing something"), 1);
	rgb[0] = map->data[F];
	rgb[1] = map->data[C];
	if (check_rgb_values(rgb) != 0)
		return (1);
	return (0);
}
