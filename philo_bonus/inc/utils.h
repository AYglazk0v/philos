#ifndef UTILS_H
# define UTILS_H

# include "philo_bonus.h"

//validator.c
int			ft_atoi(const char *str);
int			ft_valid_and_pars(int ac, char **av, t_param *prm);

//parser.c
void		ft_parser(int ac, char **av, t_param *settings);

//init.c
int			ft_init_prm(t_param *p);
int			ft_create_process(t_param *prm);

//utils.c
void		*ft_memset(void *s, int c, size_t n);

//routine.c
long int	ft_diff_time(struct timeval time, struct timeval start);
void		*routine(void *arg);
void		ft_even_synchronization(t_phil *ph);
int			ft_usleep(int action_lenght, t_phil *ph);

#endif