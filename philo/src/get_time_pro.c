/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_pro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:30:59 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/26 21:46:01 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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
		if (am_i_dead(philoso))
			return (1);
	}
	return (0);
}
