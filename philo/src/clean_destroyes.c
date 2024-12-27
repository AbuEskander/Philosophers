/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_destroyes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:37:25 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/27 17:23:14 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	clean_destroyes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nop && table->forks)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->dead);
	free(table->forks);
	free(table->allphiloso);
}
