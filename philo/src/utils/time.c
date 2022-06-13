#include "../../inc/utils.h"

static long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_waiting(long to_wait, t_control *cntr)
{
	long int	current;

	current = ft_get_time();
	while (ft_get_time() < current + to_wait
		&& ft_check_alive(cntr) == CONTINUE)
		usleep(100);
	return (ft_check_alive(cntr));
}

long	ft_diff_time(struct timeval start)
{
	long	t;
	long	s;

	t = ft_get_time();
	s = start.tv_sec * 1000 + start.tv_usec / 1000;
	return (t - s);
}
