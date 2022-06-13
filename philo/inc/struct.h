#ifndef STRUCT_H
# define STRUCT_H

# include "philo.h"

# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define FORK 4
# define DEAD 5
# define CONTINUE 6
# define STOP 7

typedef struct s_settings
{
	int	cnt_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	cnt_eat;
}	t_settings;

typedef struct s_control
{
	pthread_mutex_t		m_display;
	pthread_mutex_t		m_state;
	pthread_mutex_t		m_all_alive;
	pthread_mutex_t		m_nb_meals;
	pthread_mutex_t		*forks;
	t_settings			settings;
	struct s_phil		*philo;
	int					all_alive;
}	t_control;

typedef struct s_phil
{
	int				id;
	int				l_fork;
	int				r_fork;
	int				status;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_ate;
	struct timeval	start_time;
	struct timeval	last_eat_time;
	pthread_t		philo;
	t_control		*cntr;
}	t_phil;

#endif
