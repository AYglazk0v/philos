#ifndef STRUCT_H
# define STRUCT_H

# include "philo.h"

typedef struct s_settings
{
	size_t	cnt_philo;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	cnt_eat;
}	t_settings;

typedef struct s_phil
{
	size_t			id;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			n_ate;
	size_t			*is_end;
	time_t			start_ime;
	time_t			last_eat_time;
	pthread_t		philo;
	pthread_mutex_t	fork;
	pthread_mutex_t	event;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*is_end_lock;
}	t_phil;

typedef struct s_common_var
{
	size_t			is_end;
	pthread_mutex_t	is_end_lock;
}	t_common_var;

#endif
