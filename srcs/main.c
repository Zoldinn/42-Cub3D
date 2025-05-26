#include "../cub3d.h"

int	check_extension(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len <= 4)
		return (1);
	else if (file_name[len - 4] != '.'
		|| file_name[len - 3] != 'c'
		|| file_name[len - 2] != 'u'
		|| file_name[len - 1] != 'b')
		return (1);
	return (0);
}

static int	check_args(int argc, char **argv)
{

	if (argc < 2)
	{
		p_er("An argument including a map in .cub format is required.");
		return (1);
	}
	else if (argc > 2)
		return (p_er("Too many arguments."), 1);
	else
	{
		if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) == NULL)
			return (p_er("Map file isn't .cub"), 1);
	}
	if (check_extension(argv[1]) != 0)
		return (p_er("Map file isn't .cub"), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mtd	mtd;
	t_map map;

	if (check_args(argc, argv) != 0)
		return (1);
	get_map(&map);
	if (check_file(argv[1], &mtd) != 0)
		return (1);
	return (0);
}
