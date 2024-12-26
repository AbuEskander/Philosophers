/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:31:35 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/26 14:39:23 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

// int     eating(t_philosofo *philoso)
// {
        
// }

int     thinking(t_philosofo *philoso)
{
        printf(" %llu ms  %d is thinking  \n",philoso->wokeup - philoso->sim_start, philoso->id);
        return (0);
}
int     sleeping(t_philosofo *philoso)
{
        printf(" %llu ms  %d is sleeping \n", get_time_fixed()
		- philoso->sim_start, philoso->id);
	actual_sleep(get_time_fixed(),philoso->tts);
	philoso->wokeup = get_time_fixed();//Current Time
        return (0);
}