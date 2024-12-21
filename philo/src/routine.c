/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:08:54 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/21 16:24:48 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static	void	time_calculate(void)
{
	struct timeval timee;
	static long intial;
	static long current;
	long new_time;

	gettimeofday(&timee,NULL);
	if(!intial)
		intial = timee.tv_usec;
	if(!current)
		current = timee.tv_usec;
	else
	{
		new_time = timee.tv_usec - intial;
		current = new_time - current;
	}
	printf("Intial Time : %ld , Current time %ld , Last Time Stamp (%ld)",intial,current,new_time);

}
void	*routine(void *args)
{
	t_philosofo *philoso;
	struct timeval current;
	long next_time_intervel;
	long current_time;

	gettimeofday(&current, NULL);
	next_time_intervel = current.tv_usec;
	philoso = (t_philosofo *)args;
	while (1 && philoso->nuofm)
	{
		time_calculate();
		gettimeofday(&current, NULL);
		current_time = (current.tv_usec - next_time_intervel);
		printf("%ld I'm sleeping  %d \n", current_time, philoso->id);
		usleep(philoso->tts * 1000);
		printf("I'm eating %d\n", philoso->id);
		usleep(philoso->tte * 1000);
		philoso->nuofm--;
	}
	return (NULL);
}