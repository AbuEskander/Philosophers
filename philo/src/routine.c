/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:08:54 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/25 10:45:58 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*routine(void *args)
{
	t_philosofo *philoso;
	
	philoso = (t_philosofo *)args;
	while (1 && philoso->nuofm)
	{
		printf(" %llu ms  %d is sleeping \n",get_time_fixed() - philoso->last_meal , philoso->id);
		usleep(philoso->tts * 1000);
		pthread_mutex_lock(philoso->rightf);
		printf(" %llu ms  %d has taken a fork \n",get_time_fixed() - philoso->last_meal , philoso->id);
		pthread_mutex_lock(philoso->leftf);
		printf(" %llu ms  %d has taken a fork \n",get_time_fixed() - philoso->last_meal , philoso->id);
		printf(" %llu ms  %d is eating \n",get_time_fixed() - philoso->last_meal , philoso->id);
		usleep(philoso->tte * 1000);
		philoso->nuofm--;
		pthread_mutex_unlock(philoso->leftf);
		pthread_mutex_unlock(philoso->rightf);

	}

	return (NULL);
}