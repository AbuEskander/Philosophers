/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:23:22 by bismail           #+#    #+#             */
/*   Updated: 2025/01/01 18:48:05 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int     am_i_dead_bonus(t_philosofo *philoso)
{
        sem_wait(philoso->death);
        if((int)(get_time_fixed() - philoso->last_meal) > philoso->ttd)
        {
                if(*(philoso->did_i) == -1)
                {
                        //*(philoso->did_i) = philoso->id;
			philoso->time_of_death = get_time_fixed();
			usleep(philoso->ttd * 1000);
                }
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