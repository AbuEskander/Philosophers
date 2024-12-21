/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:28:44 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/21 14:44:27 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	init_threads(t_table *table)
{
	int i;

	table->allphiloso = malloc(sizeof(t_philosofo) * table->nop);
	if (!table->allphiloso)
		return (EXIT_FAILURE);
	i = 0;
	while (i < table->nop)
	{
		table->allphiloso[i].id = i + 1;
		table->allphiloso[i].nuofm = table->nuofm;
		table->allphiloso[i].ttd = table->ttd;
		table->allphiloso[i].tte = table->tte;
		table->allphiloso[i].tts = table->tts;

		pthread_create(&(table->allphiloso[i].tid), NULL, routine,
				&table->allphiloso[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}