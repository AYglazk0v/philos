/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:31:43 by gtaggana          #+#    #+#             */
/*   Updated: 2022/06/14 11:31:44 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

int	main(int ac, char **av)
{
	t_param		prm;

	if (ft_valid_and_pars(ac, av, &prm))
		return (printf("Argument Validity Trouble😿\n"));
	if (ft_init_prm(&prm))
		return (printf("InIT FAIL\n"));
	if (ft_create_process(&prm))
		return (printf("Thread problems\n"));
	free(prm.pid);
	return (0);
}
