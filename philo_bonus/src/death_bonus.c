/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:23:22 by bismail           #+#    #+#             */
/*   Updated: 2025/01/02 13:13:31 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	am_i_dead_bonus(t_philosofo *philoso)
{
	sem_wait(philoso->death);
	if ((int)(get_time_fixed() - philoso->last_meal) > philoso->ttd)
	{
		sem_post(philoso->death);
		return (1);
	}
	sem_post(philoso->death);
	return (0);
}

void	announce_death(t_philosofo *philoso)
{
	printf(" %llu ms %d has died \n", philoso->time_of_death
		- philoso->sim_start, philoso->id);
}
