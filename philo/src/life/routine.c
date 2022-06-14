/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:30:38 by gtaggana          #+#    #+#             */
/*   Updated: 2022/06/14 11:30:39 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/life.h"

static void	ft_for_one(t_phil *ph)
{
	ft_upd_status(ph, FORK);
	pthread_mutex_lock(&(ph->cntr->forks[ph->l_fork]));
	ft_print_status(ph);
	ft_waiting(ph->cntr->settings.time_to_die, ph->cntr);
	ft_upd_status(ph, DEAD);
	pthread_mutex_unlock(&(ph->cntr->forks[ph->l_fork]));
}

static int	ft_eating(t_phil *ph)
{
	ft_upd_status(ph, FORK);
	pthread_mutex_lock(&(ph->cntr->forks[ph->l_fork]));
	ft_print_status(ph);
	pthread_mutex_lock(&(ph->cntr->forks[ph->r_fork]));
	ft_print_status(ph);
	ft_upd_status(ph, EATING);
	ft_print_status(ph);
	return (ft_waiting(ph->cntr->settings.time_to_eat, ph->cntr));
}

static int	ft_sleeping(t_phil *ph)
{
	if (!ft_check_limits(ph->cntr))
		return (STOP);
	ft_upd_status(ph, SLEEPING);
	ft_print_status(ph);
	return (ft_waiting(ph->cntr->settings.time_to_sleep, ph->cntr));
}

static void	ft_routine_continue(t_phil *ph)
{
	int	status;

	if (ph->l_fork == ph->r_fork)
	{
		ft_for_one(ph);
		return ;
	}
	status = ft_eating(ph);
	pthread_mutex_unlock(&(ph->cntr->forks[ph->l_fork]));
	pthread_mutex_unlock(&(ph->cntr->forks[ph->r_fork]));
	if (status == STOP)
		return ;
	pthread_mutex_lock(&(ph->cntr->m_nb_meals));
	ph->n_ate++;
	pthread_mutex_unlock(&(ph->cntr->m_nb_meals));
	if (ft_sleeping(ph) == STOP)
		return ;
	ft_upd_status(ph, THINKING);
	ft_print_status(ph);
}

void	*ft_routine(void *prm)
{
	t_phil	*ph;

	ph = (t_phil *)prm;
	if (ph->id % 2 == 0)
		usleep(500);
	while (1)
	{
		if (ft_check_limits(ph->cntr) == STOP)
			break ;
		ft_routine_continue(ph);
		usleep(100);
	}
	return (NULL);
}
