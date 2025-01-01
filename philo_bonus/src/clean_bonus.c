/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 01:01:17 by abueskander       #+#    #+#             */
/*   Updated: 2025/01/01 21:59:19 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <philo_bonus.h>

void    unlink_semaphores(t_philosofo *philoso,t_table *table)
{
        if(philoso->forks != SEM_FAILED)
                sem_close(philoso->forks);
        if(philoso->death != SEM_FAILED)
                sem_close(philoso->death);
        if(philoso->wce != SEM_FAILED)
                sem_close(philoso->wce);
        free(table->allphiloso);
}
void	clean_destroyes(t_table *table, int pid)
{
        if(table->forks != SEM_FAILED)
                sem_close(table->forks);
        if(table->dead != SEM_FAILED)
                sem_close(table->dead);
        if(table->wce != SEM_FAILED)
                sem_close(table->wce);
        if(pid != 0)
        {
        sem_unlink(FORKS);
        sem_unlink(DEATH);
        sem_unlink(WHO_CAN_EAT);
        }       
	free(table->allphiloso);
}