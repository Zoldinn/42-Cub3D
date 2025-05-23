#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"


#endif
typedef struct s_map
{
	char	**data;
	int		rows;
}	t_map;

/**========================================================================
 *!                           CHECK ERRORS
 *========================================================================**/
int		check_extension(char *file_name);
void	p_er(char *str);
/**========================================================================
 *!                              PARSING
 *========================================================================**/
int		get_map(t_map *map);
/**========================================================================
 *!                               UTILS
 *========================================================================**/
char	*ft_straddstr(char *s1, char *s2);
void	free_db_array(char **arr);
int		ft_check_atoi(const char *nptr);

#endif
