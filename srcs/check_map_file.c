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

char	**get_file(char *path)
{
	int		fd;
	int		i;
	char	**file;

	fd = open(path, O_RDONLY);
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
	if (i >= 20000)
		return (p_er("your map is too big !"), free_db_array(file), NULL);
	else if (i <= 9)
		return (p_er("your file is too small ?"), free_db_array(file), NULL);
	close(fd);
	return (file);
}

int	get_mtd(t_mtd *mtd, char **id)
{
	int		i;
	int		j;
	char	**line;

	i = -1;
	while (mtd->file[++i])
	{
		line = ft_split(mtd->file[i], " \n\t\0");
		if (!line)
			return (1);
		j = -1;
		while (id[++j])
		{
			if (ft_cmpstr(line[0], id[j]) == 0)
			{
				if (mtd->txt[j].found == 0)
				{
					mtd->txt[j].found = 1;
					mtd->txt[j].path = ft_straddstr(mtd->txt[j].path, line[1]);
				}
				else
					return (p_er("there's already this texture"), 1);
			}
			
		}
	}
	return (0);
}

char	**id(void)
{
	char	**id;

	id = ft_calloc(sizeof(char *), 7);
	if (!id)
		return (1);
	id[0] = "NO";
	id[1] = "SO";
	id[2] = "WE";
	id[3] = "EA";
	id[4] = "F";
	id[5] = "C";
	return (id);
}

int	check_file(char *path, t_mtd *mtd)
{

	mtd->file = get_file(path);
	if (!mtd->file)
		return (1);
	if (get_mtd(mtd, id()) != 0)
		return (1);
}
