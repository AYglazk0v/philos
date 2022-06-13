#include "../../inc/utils.h"

long int	ft_diff_time(struct timeval time, struct timeval start)
{
	long int	during;

	during = (time.tv_sec * 1000 + time.tv_usec / 1000)
		- (start.tv_sec * 1000 + start.tv_usec / 1000);
	return (during);
}

int	ft_usleep(int action_lenght, t_phil *ph)
{
	struct timeval	start;
	struct timeval	end;
	int				time;

	time = 0;
	gettimeofday(&start, NULL);
	while (time < action_lenght)
	{
		gettimeofday(&end, NULL);
		time = ((end.tv_sec * 1000000 + end.tv_usec)
				- (start.tv_sec * 1000000 + start.tv_usec));
		usleep(1 * ph->prm->cnt_philo);
	}
	return (0);
}

void	ft_even_synchronization(t_phil *ph)
{
	if (!(ph->id % 2))
	{
		ft_usleep(ph->prm->time_to_eat * 1000 / 2, ph);
		if (ph->id == (ph->prm->cnt_philo - 1))
			ft_usleep(ph->prm->time_to_eat * 1000 / 2, ph);
	}
}

void	*routine(void *arg)
{
	t_phil	*ph;
	int		time;

	ph = (t_phil *)arg;
	while (1)
	{
		sem_wait(ph->prm->sem_death);
		gettimeofday(&ph->check_die, NULL);
		time = ft_diff_time(ph->check_die, ph->prm->start_eat);
		if (time > ph->prm->time_to_die)
		{
			ft_speak(ph, "died\n");
			sem_wait(ph->prm->sem_print);
			sem_post(ph->prm->sem_death);
			exit (1);
		}
		if (ph->prm->cnt_eat && ph->prm->time == ph->prm->cnt_eat)
		{
			sem_post(ph->prm->sem_death);
			exit (0);
		}
		sem_post(ph->prm->sem_death);
		usleep(900);
	}
	return (NULL);
}