/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:28:44 by abueskander       #+#    #+#             */
/*   Updated: 2025/01/22 12:54:59 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	init_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nop)
	{
		table->allphiloso[i].id = i + 1;
		table->allphiloso[i].nuofm = table->nuofm;
		table->allphiloso[i].ttd = table->ttd;
		table->allphiloso[i].tte = table->tte;
		table->allphiloso[i].tts = table->tts;
		table->allphiloso[i].sim_start = get_time_fixed();
		table->allphiloso[i].last_meal = get_time_fixed();
		table->allphiloso[i].leftf = &table->forks[i];
		table->allphiloso[i].rightf = &table->forks[(i + 1) % table->nop];
		table->allphiloso[i].death = table->dead;
		table->allphiloso[i].print = table->print;
		table->allphiloso[i].did_i = &table->who_is_dead;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nop);
	if (!table->forks)
		return (EXIT_FAILURE);
	while (i < table->nop)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) == -1)
			return (EXIT_FAILURE);
		i++;
	}
	table->dead = malloc(sizeof(pthread_mutex_t));
	if (!table->dead)
		return (EXIT_FAILURE);
	table->print = malloc(sizeof(pthread_mutex_t));
	if (!table->print)
		return (EXIT_FAILURE);
	pthread_mutex_init(table->print, NULL);	
	pthread_mutex_init(table->dead, NULL);
	return (EXIT_SUCCESS);
}

int	start_threading(t_table *table)
{
	int	i;
	int	fail;

	i = 0;
	fail = 0;
	while (i < table->nop)
	{
		if (pthread_create(&table->allphiloso[i].tid, NULL, routine,
				&table->allphiloso[i]) != 0)
		{
			pthread_mutex_lock(table->dead);
			usleep(table->ttd);
			pthread_mutex_unlock(table->forks);
			fail = 1;
			break ;
		}
		i++;
	}
	i = 0;
	while (i < table->nop)
		pthread_join(table->allphiloso[i++].tid, NULL);
	if (fail)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
