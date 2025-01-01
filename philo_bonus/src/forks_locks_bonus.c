/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_locks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:13:36 by bismail           #+#    #+#             */
/*   Updated: 2025/01/01 21:36:38 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void     lock_forks(t_philosofo *philoso)
{
        sem_wait(philoso->wce);
        sem_wait(philoso->forks);
}

void     unlock_forks(t_philosofo *philoso)
{
        sem_post(philoso->forks);
        sem_post(philoso->forks);
	sem_post(philoso->wce);
}