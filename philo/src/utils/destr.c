#include "../../inc/utils.h"

void	ft_destr_mutex(size_t cnt, t_phil *ph, t_common_var *cm)
{
	size_t	id;

	pthread_mutex_destroy(&(cm->is_end_lock));
	id = -1;
	while (++id < cnt)
	{
		pthread_mutex_destroy(&(ph->fork));
		pthread_mutex_destroy(&(ph->event));
	}
}
