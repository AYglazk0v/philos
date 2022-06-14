/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:30:52 by gtaggana          #+#    #+#             */
/*   Updated: 2022/06/14 11:30:53 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

void	ft_parser(int ac, char **av, t_settings *settings)
{
	settings->cnt_philo = ft_atoi(av[1]);
	settings->time_to_die = ft_atoi(av[2]);
	settings->time_to_eat = ft_atoi(av[3]);
	settings->time_to_sleep = ft_atoi(av[4]);
	settings->cnt_eat = -1;
	if (ac == 6)
		settings->cnt_eat = ft_atoi(av[5]);
}
