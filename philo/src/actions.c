/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:31:35 by abueskander       #+#    #+#             */
/*   Updated: 2025/01/06 07:20:26 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	eating(t_philosofo *philoso)
{
	lock_forks(philoso);
	if (am_i_dead(philoso))
	{
		unlock_forks(philoso);
		return (1);
	}
	pthread_mutex_lock(philoso->print);
	printf(" %llu ms  %d has taken a fork \n", get_time_fixed()
		- philoso->sim_start, philoso->id);
	printf(" %llu ms  %d has taken a fork \n", get_time_fixed()
		- philoso->sim_start, philoso->id);
	printf(" %llu ms  %d is eating \n", get_time_fixed() - philoso->sim_start,
		philoso->id);
	pthread_mutex_unlock(philoso->print);
	philoso->last_meal = get_time_fixed();
	actual_sleep(get_time_fixed(), philoso->tte, philoso);
	unlock_forks(philoso);
	return (0);
}

int	thinking(t_philosofo *philoso)
{
	if (am_i_dead(philoso))
		return (1);
	pthread_mutex_lock(philoso->print);
	printf(" %llu ms  %d is thinking  \n", get_time_fixed()
		- philoso->sim_start, philoso->id);
	pthread_mutex_unlock(philoso->print);
	return (0);
}

int	sleeping(t_philosofo *philoso)
{
	if (am_i_dead(philoso))
		return (1);
	pthread_mutex_lock(philoso->print);	
	printf(" %llu ms  %d is sleeping \n", get_time_fixed() - philoso->sim_start,
		philoso->id);
	pthread_mutex_unlock(philoso->print);
	actual_sleep(get_time_fixed(), philoso->tts, philoso);
	philoso->wokeup = get_time_fixed();
	return (0);
}
