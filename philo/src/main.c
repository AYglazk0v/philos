#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_settings		settings;
	t_common_var	common_var;
	t_phil			*phil;

	if (ft_valid_and_pars(ac, av, &settings))
		return (printf("Argument Validity Trouble😿\n"));
	if (ft_init_phil(&settings, &phil, &common_var))
		return (printf("The trouble with memory allocation!😳\n"));
	if (ft_init_mutex(settings.cnt_philo, phil, &common_var))
	{
		free(phil);
		return (printf("The trouble with mutex!🤬\n"));
	}
	return (0);
}
