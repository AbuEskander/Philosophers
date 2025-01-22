/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_destroyes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:37:25 by abueskander       #+#    #+#             */
/*   Updated: 2025/01/22 12:55:37 by bismail          ###   ########.fr       */
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
	free(table->print);
	free(table->allphiloso);
}
