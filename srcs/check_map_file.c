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
		values = ft_split(rgb[i], ',');
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

// char	*find_arg(char *id)

char	**get_file(char *file_name)
{
	int		fd;
	int		i;
	char	**file;

	fd = open(file_name, O_RDONLY);
	file = ft_calloc(sizeof(char *), 20000);
	if (!file)
		return (NULL);
	i = -1;
	while (++i < 20000)
	{
		file[i] = get_next_line(fd);
		if (file[i] == NULL)
			break ;
	}
	// check qu'il y a quelque chose dans le fichier
	if (i >= 20000)
		return (p_er("your map is too big !"), NULL);

}

int	check_file(char *file_name)
{
	
}