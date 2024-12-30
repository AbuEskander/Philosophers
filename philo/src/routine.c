/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:08:54 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/30 15:56:03 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	lock_forks(t_philosofo *philoso)
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

void	unlock_forks(t_philosofo *philoso)
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
	if (philoso->leftf == philoso->rightf)
	{
		thinking(philoso);
		while (!am_i_dead(philoso))
			;
		return (NULL);
	}
	while (philoso->nuofm)
	{
		if (eating(philoso))
			break ;
		if (sleeping(philoso))
			break ;
		if (thinking(philoso))
			break ;
		philoso->nuofm--;
	}
	return (NULL);
}
