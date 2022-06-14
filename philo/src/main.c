/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:31:07 by gtaggana          #+#    #+#             */
/*   Updated: 2022/06/14 11:31:07 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_settings		settings;
	t_control		cntr;
	struct timeval	time;

	if (ft_valid_and_pars(ac, av, &settings))
		return (printf("Argument Validity Trouble😿\n"));
	if (ft_init_cntr(&cntr, settings))
		return (printf("The trouble with memory allocation!😳\n"));
	if (ft_init_mutex(&cntr, settings))
		return (printf("The trouble with mutex!🤬\n"));
	if (gettimeofday(&time, NULL))
		return (printf("WHAT?! ERROR IN GETTIME?!"));
	if (ft_init_philo(&cntr, time))
		return (printf("The trouble with init philo!😳\n"));
	if (ft_runtime(&cntr))
		return (1);
	return (0);
}
