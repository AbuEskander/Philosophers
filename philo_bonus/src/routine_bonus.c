/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:19:44 by bismail           #+#    #+#             */
/*   Updated: 2025/01/03 21:13:33 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static int	solo_death(t_philosofo *philoso)
{
	while (1)
	{
		actual_sleep(get_time_fixed(), philoso->ttd, philoso);
		if (am_i_dead_bonus(philoso))
			break ;
	}
	return (EXIT_FAILURE);
}

void	routine(t_philosofo *philoso, t_table *table)
{
	int	id;

	id = 0;
	philoso->child_id = getpid();
	if (table->nop == 1)
	{
		thinking(philoso);
		solo_death(philoso);
	}
	while (philoso->nuofm && table->nop > 1)
	{
		if (eating(philoso))
			break ;
		if (sleeping(philoso))
			break ;
		if (thinking(philoso))
			break ;
		philoso->nuofm--;
	}
	if (philoso->nuofm == 0)
		id = 0;
	else
		id = philoso->id;
	unlink_semaphores(philoso, table);
	exit(id);
}
