/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:15:00 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/30 12:06:09 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# define MAX_ARGS 6
# define MIN_ARGS 5
# define NOMEALCOUNT -1

typedef unsigned long long	t_timelen;

typedef struct s_philosopho
{
	int						id;
	pthread_t				tid;
	int						tts;
	int						ttd;
	int						tte;
	int						nuofm;
	t_timelen				sim_start;
	t_timelen				wokeup;
	t_timelen				last_meal;
	pthread_mutex_t			*leftf;
	pthread_mutex_t			*rightf;
	pthread_mutex_t			*death;
	int						*did_i;
	t_timelen				time_of_death;

}							t_philosofo;

typedef struct s_table
{
	int						nop;
	int						tts;
	int						ttd;
	int						tte;
	int						nuofm;
	t_philosofo				*allphiloso;
	sem_t			*forks;
	sem_t			*dead;
	int						who_is_dead;
}							t_table;

enum						e_inputs
{
	NUMBEROFP = 1,
	TIMETODIE,
	TIMETOEAT,
	TIMETOSLEEP,
	NUMBEROFMEALS
};

void						display_error(char *str);
void						ft_putstr(char *str, int fd);
long						ft_atoi(const char *nptr);
int							check_number(char *item);
int							check_numbers(char **number);
int							onlydigits(char *str);
size_t						ft_strlen(char *str);
size_t						total_len(ssize_t n);
t_timelen	get_time_fixed(void);
int    							init_process(t_table *s);

#endif