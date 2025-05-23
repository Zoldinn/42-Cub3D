#include "../cub3d.h"

//add s2 after s1 
//and free(s1)
//(kind of realloc)
char	*ft_straddstr(char *s1, char *s2)
{
	char	*res;

	if (s1 == NULL)
	{
		if (s2 == NULL)
			return (NULL);
		res = ft_strdup(s2);
		return (res);
	}
	else
	{
		res = ft_strjoin(s1, s2);
		free(s1);
		return (res);
	}
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
