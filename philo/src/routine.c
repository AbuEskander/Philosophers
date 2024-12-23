/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:08:54 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/23 23:24:34 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*routine(void *args)
{
	t_philosofo *philoso;
	
	philoso = (t_philosofo *)args;

	if(pthread_mutex_lock(&philoso->rightf))
		return (NULL);
	if(pthread_mutex_lock(&philoso->leftf))
		return (NULL);	
	while (1 && philoso->nuofm)
	{
		
		printf("I'm sleeping %d \n", philoso->id);
		usleep(philoso->tts * 1000);
		printf("I'm eating %d\n", philoso->id);
		usleep(philoso->tte * 1000);
		philoso->nuofm--;
	}

	return (NULL);
}