/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:30:42 by gtaggana          #+#    #+#             */
/*   Updated: 2022/06/14 11:30:44 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/life.h"

int	ft_runtime(t_control *cntr)
{
	t_phil	*ph;
	int		i;

	i = -1;
	while (++i < cntr->settings.cnt_philo)
	{
		ph = cntr->philo + i;
		if (pthread_create(&(ph->philo), NULL, &ft_routine, ph))
			return (ft_p_faild(cntr, "Trouble with streams!\n"));
	}
	while (ft_check_limits(cntr) == CONTINUE)
		usleep(100);
	i = -1;
	while (++i < cntr->settings.cnt_philo)
	{
		ph = cntr->philo + i;
		if (pthread_join(ph->philo, NULL))
			return (ft_p_faild(cntr, "The glue is dry (join)!"));
	}
	return (ft_p_faild(cntr, ""));
}
