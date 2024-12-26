/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:31:35 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/26 21:45:02 by abueskander      ###   ########.fr       */
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
	printf(" %llu ms  %d has taken a fork \n", get_time_fixed()
		- philoso->sim_start, philoso->id);
	printf(" %llu ms  %d has taken a fork \n", get_time_fixed()
		- philoso->sim_start, philoso->id);
	printf(" %llu ms  %d is eating \n", get_time_fixed() - philoso->sim_start,
		philoso->id);
	philoso->last_meal = get_time_fixed();
	actual_sleep(get_time_fixed(), philoso->tte, philoso);
	unlock_forks(philoso);
	return (0);
}

int	thinking(t_philosofo *philoso)
{
	if (am_i_dead(philoso))
		return (1);
	printf(" %llu ms  %d is thinking  \n", get_time_fixed()
		- philoso->sim_start, philoso->id);
	return (0);
}

int	sleeping(t_philosofo *philoso)
{
	if (am_i_dead(philoso))
		return (1);
	printf(" %llu ms  %d is sleeping \n", get_time_fixed() - philoso->sim_start,
		philoso->id);
	actual_sleep(get_time_fixed(), philoso->tts, philoso);
	philoso->wokeup = get_time_fixed();
	return (0);
}
