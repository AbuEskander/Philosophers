/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_pro_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:53:31 by abueskander       #+#    #+#             */
/*   Updated: 2025/01/02 13:12:45 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

t_timelen	get_time_fixed(void)
{
	struct timeval	time;
	t_timelen		current_time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_time);
}

t_timelen	actual_sleep(t_timelen time, t_timelen time_to_wait,
		t_philosofo *philoso)
{
	while (get_time_fixed() - time < time_to_wait)
	{
		if (am_i_dead_bonus(philoso))
			break ;
	}
	return (0);
}
