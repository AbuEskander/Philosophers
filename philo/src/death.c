/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:32:25 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/26 21:45:18 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	am_i_dead(t_philosofo *philoso)
{
	pthread_mutex_lock(philoso->death);
	if ((int)(get_time_fixed() - philoso->last_meal) >= philoso->ttd)
	{
		if (*(philoso->did_i) == -1)
		{
			*(philoso->did_i) = philoso->id;
			philoso->time_of_death = get_time_fixed();
		  usleep(philoso->ttd * 1000);
    }
     pthread_mutex_unlock(philoso->death);
		return (1);
	}
	pthread_mutex_unlock(philoso->death);
	return (0);
}

void	announce_death(t_philosofo *philoso)
{
	printf(" %llu ms %d has died \n", philoso->time_of_death
		- philoso->sim_start, philoso->id);
}
