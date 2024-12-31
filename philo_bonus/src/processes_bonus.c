/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:54:20 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/30 16:34:34 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int    init_process(t_table *table)
{
        int     i;

        i = 0;
        while (i < table->nop)
        {
                table->allphiloso[i].id = i + 1;
		table->allphiloso[i].nuofm = table->nuofm;
		table->allphiloso[i].ttd = table->ttd;
		table->allphiloso[i].tte = table->tte;
		table->allphiloso[i].tts = table->tts;
		table->allphiloso[i].sim_start = get_time_fixed();
		table->allphiloso[i].last_meal = get_time_fixed();
		table->allphiloso[i].leftf = &table->forks[i];
		table->allphiloso[i].rightf = &table->forks[(i + 1) % table->nop];
		table->allphiloso[i].death = table->dead;
		table->allphiloso[i].did_i = &table->who_is_dead;
                i++;
        }
}