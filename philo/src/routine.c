/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:08:54 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/26 14:39:55 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	lock_forks(t_philosofo *philoso)
{
	if (philoso->id % 2 == 0)
	{
		pthread_mutex_lock(philoso->rightf);
		pthread_mutex_lock(philoso->leftf);
	}
	else
	{
		pthread_mutex_lock(philoso->leftf);
		pthread_mutex_lock(philoso->rightf);
	}
}
static void	unlock_forks(t_philosofo *philoso)
{
	if (philoso->id % 2 == 0)
	{
		pthread_mutex_unlock(philoso->leftf);
		pthread_mutex_unlock(philoso->rightf);
	}
	else
	{
		pthread_mutex_unlock(philoso->rightf);
		pthread_mutex_unlock(philoso->leftf);
	}
}

void	*routine(void *args)
{
	t_philosofo	*philoso;

	philoso = (t_philosofo *)args;
	while (philoso->nuofm)
	{
		
		sleeping(philoso);
		thinking(philoso);
		lock_forks(philoso);
		printf(" %llu ms  %d has taken a fork \n", get_time_fixed()
				- philoso->sim_start, philoso->id);
		printf(" %llu ms  %d has taken a fork \n", get_time_fixed()
				- philoso->sim_start, philoso->id);
		printf(" %llu ms  %d is eating \n", get_time_fixed()
				- philoso->sim_start, philoso->id);
		actual_sleep(get_time_fixed(),philoso->tte);
		philoso->nuofm--;
		unlock_forks(philoso);
	
	}
	return (NULL);
}
/*
 0 200 '100' 100
-----    ----
*/