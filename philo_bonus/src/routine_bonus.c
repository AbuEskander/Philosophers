/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:19:44 by bismail           #+#    #+#             */
/*   Updated: 2025/01/01 22:10:16 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>


void    routine(t_philosofo *philoso,t_table *table)
{
	int	id = 0;
        philoso->child_id = getpid();
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
	if(philoso->nuofm == 0)
		id = 0;
	else
		id = philoso->id;
	unlink_semaphores(philoso,table);
        exit(id);
}