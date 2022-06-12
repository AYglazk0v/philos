#ifndef UTILS_H
# define UTILS_H

# include "philo.h"

//validator.c
int	ft_atoi(const char *str);
int	ft_isspace(int c);
int	ft_atoi(const char *str);
int ft_isnum(char *s);
int	ft_valid_and_pars(int ac, char **av, t_settings *settings);

//parser.c
void	ft_parser(int ac, char **av, t_settings *settings);

//init.c
int	ft_init_phil(t_settings *st, t_phil **ph, t_common_var *cm);
int	ft_init_mutex(size_t cnt, t_phil *ph, t_common_var *cm);

//destr.c
void	ft_destr_mutex(size_t cnt, t_phil *ph, t_common_var *cm);
#endif
