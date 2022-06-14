/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:31:37 by gtaggana          #+#    #+#             */
/*   Updated: 2022/06/14 11:43:09 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int	k;

	k = (int)n;
	while (--k >= 0)
	{
		*((unsigned char *)(s + k)) = (char)c;
	}
	return (s);
}

void	ft_helpunlink(int cnt)
{
	if (cnt == 1)
		sem_unlink("/sem_death");
	else if (cnt == 2)
	{
		sem_unlink("/sem_death");
		sem_unlink("/sem_print");
	}
	else if (cnt == 3)
	{
		sem_unlink("/sem_death");
		sem_unlink("/sem_print");
		sem_unlink("/sem_fork");
	}
}
