#include "../../inc/utils.h"

void	ft_parser(int ac, char **av, t_param *settings)
{
	settings->cnt_philo = ft_atoi(av[1]);
	settings->time_to_die = ft_atoi(av[2]);
	settings->time_to_eat = ft_atoi(av[3]);
	settings->time_to_sleep = ft_atoi(av[4]);
	settings->cnt_eat = -1;
	if (ac == 6)
		settings->cnt_eat = ft_atoi(av[5]);
	if (settings->cnt_philo % 2)
		settings->time_to_think = (settings->time_to_eat
				- settings->time_to_sleep) + (settings->time_to_eat);
}