
#include "../../inc/life.h"

void	ft_speak(t_phil *ph, char *s)
{
	int	time;

	sem_wait(ph->prm->sem_print);
	gettimeofday(&ph->start_action, NULL);
	time = ft_diff_time(ph->start_action, ph->prm->difftime);
	printf("%d %d %s", time, ph->id + 1, s);
	sem_post(ph->prm->sem_print);
}

static void	ft_eat_start(t_phil *ph)
{
	gettimeofday(&ph->prm->start_eat, NULL);
	ft_speak(ph, "is eating\n");
	ft_usleep(ph->prm->time_to_eat * 1000, ph);
}

void	ft_eat(t_phil *ph)
{	
	sem_wait(ph->prm->sem_fork);
	ft_speak(ph, "has taken a fork\n");
	sem_wait(ph->prm->sem_fork);
	ft_speak(ph, "has taken a fork\n");
	ft_eat_start(ph);
	sem_post(ph->prm->sem_fork);
	sem_post(ph->prm->sem_fork);
	sem_wait(ph->prm->sem_death);
	ph->prm->time++;
	if (ph->prm->cnt_eat && ph->prm->time == ph->prm->cnt_eat)
	{
		sem_post(ph->prm->sem_death);
		usleep(10000);
	}
	sem_post(ph->prm->sem_death);
}

void	ft_sleep(t_phil *ph)
{
	ft_speak(ph, "is sleeping\n");
	ft_usleep(ph->prm->time_to_sleep * 1000, ph);
}

void	ft_think(t_phil *ph)
{
	ft_speak(ph, "is thinking\n");
	if (ph->prm->cnt_philo % 2)
		ft_usleep(ph->prm->time_to_think * 1000, ph);
}
