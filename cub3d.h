#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_map
{
	char	**data;
	char	**map;
	char	*floor;
	char	*ceiling;
	int		rows;
	int		start_map;
}	t_map;

/**========================================================================
 *!                              PARSING
 *========================================================================**/
int		get_map(t_map *map);
/**========================================================================
 *!                               UTILS
 *========================================================================**/
char	*ft_straddstr(char *s1, char *s2);
char	*get_next_line(int fd);
/**========================================================================
 *!                               FREE
 *========================================================================**/
void	free_db_array(char **arr);
void	free_and_exit(t_map *map);
void	free_map(t_map *map);

#endif