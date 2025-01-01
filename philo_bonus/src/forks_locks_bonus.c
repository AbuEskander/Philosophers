/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_locks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:13:36 by bismail           #+#    #+#             */
/*   Updated: 2025/01/01 18:41:05 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void     lock_forks(t_philosofo *philoso)
{
        sem_wait(philoso->wce);
        sem_wait(philoso->forks);
        printf(" %llu ms  %d has taken a fork  \n", get_time_fixed() - philoso->sim_start,
		philoso->id);
        sem_wait(philoso->forks);
        printf(" %llu ms  %d has taken a fork  \n", get_time_fixed() - philoso->sim_start,
		philoso->id);
}

void     unlock_forks(t_philosofo *philoso)
{
        sem_post(philoso->forks);
        sem_post(philoso->forks);
	sem_post(philoso->wce);
}