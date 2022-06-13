#ifndef UTILS_H
# define UTILS_H

# include "philo.h"

//validator.c
int		ft_atoi(const char *str);
int		ft_valid_and_pars(int ac, char **av, t_settings *settings);

//parser.c
void	ft_parser(int ac, char **av, t_settings *settings);

//init.c
int		ft_init_cntr(t_control *cntr, t_settings settings);
int		ft_destr_all(int i, t_control *cntr);
int		ft_init_mutex(t_control *cntr, t_settings stt);
int		ft_init_philo(t_control *cntr, struct timeval t);
int		ft_p_faild(t_control *cntr, char *s);

//status.c
int		ft_check_alive(t_control *cntrl);
int		ft_check_ate(t_control *cntrl);
int		ft_check_limits(t_control *cntrl);
void	ft_upd_status(t_phil *ph, int status);

//time.c
int		ft_waiting(long to_wait, t_control *cntr);
long	ft_diff_time(struct timeval start);

//printing.c
void	ft_print_status(t_phil *ph);

#endif
