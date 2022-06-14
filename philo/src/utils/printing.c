/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:30:54 by gtaggana          #+#    #+#             */
/*   Updated: 2022/06/14 11:30:55 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

static void	ft_status_msg(t_phil *ph, long time, int id,
	int *end)
{
	int	status;

	pthread_mutex_lock(&(ph->cntr->m_state));
	status = ph->status;
	pthread_mutex_unlock(&(ph->cntr->m_state));
	if (ft_check_ate(ph->cntr))
		*end = printf("-- Everyone has eaten enough --\n");
	else if (status == DEAD)
		*end = printf("%5ld\t%d died\n", time, id);
	else if (status == FORK && ft_check_alive(ph->cntr))
		printf("%5ld\t%d has taken a fork\n", time, id);
	else if (status == EATING)
		printf("%5ld\t%d is eating\n", time, id);
	else if (status == SLEEPING)
		printf("%5ld\t%d is sleeping\n", time, id);
	else if (status == THINKING)
		printf("%5ld\t%d is thinking\n", time, id);
}

void	ft_print_status(t_phil *ph)
{
	static int	print_end;
	long		time_stamp;
	int			id;

	time_stamp = ft_diff_time(ph->start_time);
	id = ph->id;
	pthread_mutex_lock(&(ph->cntr->m_display));
	if (!print_end)
		ft_status_msg(ph, time_stamp, id, &print_end);
	pthread_mutex_unlock(&(ph->cntr->m_display));
}
