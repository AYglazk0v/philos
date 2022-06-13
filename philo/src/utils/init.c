#include "../../inc/utils.h"

int	ft_init_cntr(t_control *cntr, t_settings settings)
{
	cntr->philo = malloc(sizeof(t_phil) * (settings.cnt_philo));
	if (cntr->philo == NULL)
		return (1);
	cntr->forks = malloc(sizeof(pthread_mutex_t) * (settings.cnt_philo));
	if (cntr->forks == NULL)
	{
		free(cntr->philo);
		return (1);
	}
	cntr->settings = settings;
	cntr->all_alive = 1;
	return (0);
}

int	ft_init_mutex(t_control *cntr, t_settings stt)
{
	int	i;

	i = -1;
	while (++i < stt.cnt_philo)
	{
		if (pthread_mutex_init(&(cntr->forks[i]), NULL) != 0)
			return (ft_destr_all(i, cntr));
	}
	if (pthread_mutex_init(&(cntr->m_display), NULL) != 0)
		return (ft_destr_all(i, cntr));
	if (pthread_mutex_init(&(cntr->m_all_alive), NULL) != 0)
		return (ft_destr_all(i, cntr));
	if (pthread_mutex_init(&(cntr->m_state), NULL) != 0)
		return (ft_destr_all(i, cntr));
	if (pthread_mutex_init(&(cntr->m_nb_meals), NULL) != 0)
		return (ft_destr_all(i, cntr));
	return (0);
}


int	ft_init_philo(t_control *cntr, struct timeval t)
{
	int		i;
	t_phil	*ph;

	i = -1;
	while (++i < cntr->settings.cnt_philo )
	{
		ph = &(cntr->philo[i]);
		ph->id = i + 1;
		ph->l_fork = i;
		ph->r_fork = i + 1;
		if (i + 1 == cntr->settings.cnt_philo)
		{
			ph->l_fork = 0;
			ph->r_fork = i;
		}
		ph->status = THINKING;
		ph->last_eat_time = t;
		ph->start_time = t;
		ph->n_ate = 0;
		ph->cntr = cntr;
	}
	return (0);
}

int	ft_destr_all(int i, t_control *cntr)
{
	int	j;

	j = -1;
	while (++j < i)
		pthread_mutex_destroy(&(cntr->forks[j]));
	pthread_mutex_destroy(&(cntr->m_display));
	pthread_mutex_destroy(&(cntr->m_all_alive));
	pthread_mutex_destroy(&(cntr->m_state));
	pthread_mutex_destroy(&(cntr->m_nb_meals));
	return (1);
}

int	ft_p_faild(t_control *cntr, char *s)
{
	ft_destr_all(cntr->settings.cnt_philo, cntr);
	free(cntr->forks);
	free(cntr->philo);
	if (*s != '\0')
		return (printf("%s\n", s));
	return (0);
}
