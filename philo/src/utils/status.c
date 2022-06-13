#include "../../inc/utils.h"

int	ft_check_alive(t_control *cntrl)
{
	int	i;
	t_phil	*ph;

	i = -1;
	while (++i < cntrl->settings.cnt_philo)
	{
		ph = cntrl->philo + i;
		if (ft_diff_time(ph->last_eat_time) > cntrl->settings.time_to_die)
		{
			pthread_mutex_lock(&(cntrl->m_state));
			ph->status = DEAD;
			pthread_mutex_unlock(&(cntrl->m_state));
			pthread_mutex_lock(&(cntrl->m_all_alive));
			cntrl->all_alive = 0;
			pthread_mutex_unlock(&(cntrl->m_all_alive));
			ft_print_status(ph);
			return (STOP);
		}
	}
	return (CONTINUE);
}

int	ft_check_ate(t_control *cntrl)
{
	int	i;
	int	cnt_ate;
	int	philo_meals;

	i = -1;
	cnt_ate = cntrl->settings.cnt_eat;
	while (++i < cntrl->settings.cnt_philo)
	{
		pthread_mutex_lock(&(cntrl->m_nb_meals));
		philo_meals = cntrl->philo[i].n_ate;
		pthread_mutex_unlock(&(cntrl->m_nb_meals));
		if (philo_meals < cnt_ate || cnt_ate == -1)
			return (0);
	}
	return (1);
}

int	ft_check_limits(t_control *cntrl)
{
	if (ft_check_alive(cntrl) == STOP)
		return (STOP);
	if (ft_check_ate(cntrl) == 1)
		return (STOP);
	return (CONTINUE);
}

void	ft_upd_status(t_phil *ph, int status)
{
	t_control	*cntrl;

	cntrl = ph->cntr;
	pthread_mutex_lock(&(cntrl->m_state));
	if (ph->status != DEAD)
	{
		ph->status = status;
		if (status == EATING)
			gettimeofday(&(ph->last_eat_time), NULL);
		pthread_mutex_unlock(&(cntrl->m_state));
		return ;
	}
	pthread_mutex_unlock(&(cntrl->m_state));
}
