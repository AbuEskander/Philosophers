/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:33:36 by bismail           #+#    #+#             */
/*   Updated: 2025/01/01 18:41:10 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>


int     eating(t_philosofo *philoso)
{
        lock_forks(philoso);
        if(am_i_dead_bonus(philoso))
        {
                unlock_forks(philoso);
                return(1);
        }
        printf(" %llu ms  %d is eating \n", get_time_fixed() - philoso->sim_start,
		philoso->id);
        philoso->last_meal = get_time_fixed();
        actual_sleep(get_time_fixed(),philoso->tte,philoso);
        unlock_forks(philoso);
        return (EXIT_SUCCESS);
}

int     thinking (t_philosofo *philoso)
{
        if(am_i_dead_bonus(philoso))
                return (1);
        printf(" %llu ms  %d is thinking  \n", get_time_fixed()
		- philoso->sim_start, philoso->id);
        return (0);
}

int	sleeping(t_philosofo *philoso)
{
	if (am_i_dead_bonus(philoso))
		return (1);
	printf(" %llu ms  %d is sleeping \n", get_time_fixed() - philoso->sim_start,
		philoso->id);
	actual_sleep(get_time_fixed(), philoso->tts, philoso);
	philoso->wokeup = get_time_fixed();
	return (0);
}