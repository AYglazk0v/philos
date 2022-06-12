#include "../../inc/utils.h"

static int	ft_alloc_phil(size_t cnt_philo, t_phil **ph)
{
	*ph = (t_phil *)malloc(sizeof(t_phil) * cnt_philo);
	if (*ph == NULL)
		return (1);
	return (0);
}

int	ft_init_phil(t_settings *st, t_phil **ph, t_common_var *cm)
{
	size_t	id;

	if (ft_alloc_phil(st->cnt_philo, ph))
		return (1);
	id = -1;
	cm->is_end = 0;
	while (++id < st->cnt_philo)
	{
		(*ph)[id].id = id + 1;
		(*ph)[id].n_ate = 0;
		(*ph)[id].time_to_eat = st->time_to_eat;
		(*ph)[id].time_to_sleep = st->time_to_sleep;
		(*ph)[id].l_fork = &((*ph)[id].fork);
		(*ph)[id].r_fork = &((*ph)[(id + 1) % st->cnt_philo].fork);
		(*ph)[id].is_end = &(cm->is_end);
		(*ph)[id].is_end_lock = &(cm->is_end_lock);
	}
	return (0);
}

static int	ft_mutex_init_evnt_fork(pthread_mutex_t *fork, pthread_mutex_t *evnt)
{
	if (pthread_mutex_init(fork, NULL) != 0)
		return (1);
	if (pthread_mutex_init(evnt, NULL) != 0)
	{
		pthread_mutex_destroy(fork);
		return (1);
	}
	return (0);
}

int	ft_init_mutex(size_t cnt, t_phil *ph, t_common_var *cm)
{
	size_t	id;

	if (pthread_mutex_init(&(cm->is_end_lock), NULL) != 0)
		return (1);
	id = -1;
	while (++id < cnt)
	{
		if (ft_mutex_init_evnt_fork(&(ph[id].fork), &(ph[id].event)))
		{
			while(--id)
			{
				pthread_mutex_destroy(&(ph[id].fork));
				pthread_mutex_destroy(&(ph[id].event));
			}
			pthread_mutex_destroy(&(cm->is_end_lock));
			return (1);
		}
	}
	return (0);
}
