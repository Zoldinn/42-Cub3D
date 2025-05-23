#include "../cub3d.h"

void	p_er(char *str)
{
	ft_putstr_fd("\e[31mERROR: \e[0m", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
}

// an atoi which check nb
// if there's another thing than digit -> return -1
// (could add to check long ? -> return -1)
// if it return -1 -> error
int	ft_check_atoi(const char *nptr)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr)
	{
		if (*nptr >= '0' && *nptr <= '9')
		{
			res = (res * 10) + (*nptr - '0');
			nptr++;
		}
		else
			return (-1);
	}
	return (res * sign);
}

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
