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
