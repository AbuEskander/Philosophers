/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:54:20 by abueskander       #+#    #+#             */
/*   Updated: 2025/01/01 18:40:37 by bismail          ###   ########.fr       */
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
		table->allphiloso[i].forks = table->forks;
		table->allphiloso[i].wce = table->wce;
		table->allphiloso[i].death = table->dead;
		// table->allphiloso[i].did_i = &table->who_is_dead;
                i++;
        }
	return (EXIT_SUCCESS);
}
int	init_forks(t_table *table)
{
	sem_t	*forks;
	sem_t	*death;
	sem_t	*wce;

	sem_unlink(WHO_CAN_EAT);
	sem_unlink(FORKS);
	sem_unlink(DEATH);
	forks = sem_open(FORKS,O_CREAT | O_EXCL,0600, table->nop);
	if(forks == SEM_FAILED)
		return (EXIT_FAILURE);
	death = sem_open(DEATH,O_CREAT | O_EXCL,0600, 1);
	if(death == SEM_FAILED)
		return (EXIT_FAILURE);
	wce = sem_open(WHO_CAN_EAT,O_CREAT | O_EXCL,0600, (table->nop / 2));
	if(wce == SEM_FAILED)
		return (EXIT_FAILURE);
	table->forks = forks;
	table->dead = death;
	table->wce = wce;
	return (EXIT_SUCCESS);
}

int	start_processing(t_table *table)
{
	int	pid;
	int	i;
	int	who;

	who = 0;
	pid = -1;
	i = 0;
	while(i++ < table->nop && pid != 0)
	{
		pid = fork();
		if(pid == -1)
		{
			while(i--)
				kill(0,SIGKILL);
			return(EXIT_FAILURE);
		}
		if (pid  == 0)
		{
			routine(&table->allphiloso[who]);
		}
		who++;
	}
	
	i = 0;
	while(i++ < table->nop)
	{
		wait(0);
	}
	return (EXIT_SUCCESS);
}
