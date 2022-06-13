#include "../../inc/utils.h"

static int	ft_isspace(int c)
{
	if ((c == '\f' || c == '\n' || c == '\r'
			|| c == '\t' || c == '\v' || c == ' '))
		return (1);
	return (0);
}

static int	ft_isnum(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long unsigned int	num;
	int					sign;

	sign = 1;
	num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
		if ((num >= __LONG_MAX__) && sign > 0)
			return (-1);
		if ((num > __LONG_MAX__) && sign < 0)
			return (0);
	}
	return (sign * (int)num);
}

int	ft_valid_and_pars(int ac, char **av, t_settings *settings)
{
	int	i;

	if (ac < 5 || ac > 6)
		return (1);
	i = 0;
	while (++i < ac)
	{
		if (!ft_isnum(av[i]) || ft_atoi(av[i]) <= 0)
			return (1);
	}
	ft_parser(ac, av, settings);
	return (0);
}
