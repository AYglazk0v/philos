/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:31:20 by gtaggana          #+#    #+#             */
/*   Updated: 2022/06/14 11:31:21 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "philo_bonus.h"

typedef struct s_param
{
	int				cnt_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				cnt_eat;
	int				time_to_think;
	int				time;
	struct timeval	difftime;
	struct timeval	start_eat;
	pid_t			*pid;
	sem_t			*sem_death;
	sem_t			*sem_fork;
	sem_t			*sem_print;
	pthread_t		th;
}t_param;

typedef struct s_phil
{
	int				id;
	int				time;
	struct timeval	check_die;
	struct timeval	start_action;
	t_param			*prm;
}t_phil;

#endif
