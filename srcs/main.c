#include "../cub3d.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("An argument including a map in .cub format is required.\n");
		return (1);
	}
	else if (argc > 2)
		return (printf("Too many arguments.\n"), (1));
	else
	{
		if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) == NULL)
			return (printf("Error\nMap file isn't .cub\n"), 1);
		printf("%s\n", argv[1]);
	}
	return (0);
}