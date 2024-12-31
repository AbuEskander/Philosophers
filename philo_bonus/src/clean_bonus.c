/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 01:01:17 by abueskander       #+#    #+#             */
/*   Updated: 2025/01/01 01:49:52 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <philo_bonus.h>
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