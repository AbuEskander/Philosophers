/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:19:44 by bismail           #+#    #+#             */
/*   Updated: 2025/01/01 18:41:28 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>


void    routine(t_philosofo *philoso)
{
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
        exit(0);
}