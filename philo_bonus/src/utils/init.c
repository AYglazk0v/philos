/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:31:28 by gtaggana          #+#    #+#             */
/*   Updated: 2022/06/14 11:43:28 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

int	ft_init_prm(t_param *p)
{
	p->pid = malloc(sizeof(pid_t) * p->cnt_philo);
	if (p->pid == NULL)
		return (1);
	ft_helpunlink(3);
	p->sem_death = sem_open("/sem_death", O_CREAT | O_EXCL, 0644, 1);
	if (p->sem_death == SEM_FAILED)
		return (1);
	p->sem_print = sem_open("/sem_print", O_CREAT | O_EXCL, 0644, 1);
	if (p->sem_print == SEM_FAILED)
	{
		sem_close(p->sem_death);
		sem_unlink("/sem_death");
		return (1);
	}
	p->sem_fork = sem_open("/sem_fork", O_CREAT | O_EXCL, 0644, p->cnt_philo);
	if (p->sem_fork == SEM_FAILED)
	{
		sem_close(p->sem_death);
		sem_close(p->sem_print);
		ft_helpunlink(2);
		return (1);
	}
	return (0);
}

static void	ft_init_philo(t_phil *ph, t_param *prm)
{
	ft_memset(ph, 0, sizeof(t_phil));
	ph->prm = prm;
	gettimeofday(&ph->prm->difftime, NULL);
}

static void	ft_child_process(t_phil *ph)
{
	gettimeofday(&ph->prm->start_eat, NULL);
	if (pthread_create(&ph->prm->th, NULL, &routine, ph) != 0)
		return ;
	ft_even_synchronization(ph);
	while (1)
	{
		ft_eat(ph);
		ft_sleep(ph);
		ft_think(ph);
	}
	if (pthread_join(ph->prm->th, NULL) != 0)
		return ;
}

static void	ft_mother_process(t_phil *ph)
{
	int	i;
	int	status;

	i = -1;
	while (++i < ph->prm->cnt_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < ph->prm->cnt_philo)
				kill(ph->prm->pid[i], SIGKILL);
			break ;
		}
	}
	sem_close(ph->prm->sem_death);
	sem_close(ph->prm->sem_fork);
	sem_close(ph->prm->sem_death);
	sem_unlink("/sem_death");
	sem_unlink("/sem_fork");
	sem_unlink("/sem_print");
	free(ph);
}

int	ft_create_process(t_param *prm)
{
	int		i;
	t_phil	*ph;

	ph = malloc(sizeof (t_phil));
	if (!ph)
		return (1);
	ft_init_philo(ph, prm);
	i = -1;
	while (++i < prm->cnt_philo)
	{
		ph->id = i;
		ph->prm->pid[i] = fork();
		if (ph->prm->pid[i] == -1)
			return (1);
		if (ph->prm->pid[i] == 0)
			break ;
	}
	if (ph->prm->pid[ph->id] != 0)
		ft_mother_process(ph);
	else
	{
		free(ph->prm->pid);
		ft_child_process(ph);
	}
	return (0);
}
