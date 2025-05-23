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
	int		rows;
}	t_map;

typedef struct s_file_arg
{
	char	*id;
	char	*arg;
}			t_file_arg;

typedef struct s_to_check
{
	t_file_arg	args[6];
	t_map		map;
}				t_to_check;

/**========================================================================
 *!                           CHECK ERRORS
 *========================================================================**/
int		check_extension(char *file_name);
/**========================================================================
 *!                              PARSING
 *========================================================================**/
int		get_map(t_map *map);
char	*get_next_line(int fd);
/**========================================================================
 *!                               UTILS
 *========================================================================**/
char	*ft_straddstr(char *s1, char *s2);
void	free_db_array(char **arr);
int		ft_check_atoi(const char *nptr);
int		ft_cmpstr(char *s1, char *s2);
void	p_er(char *str);

#endif
