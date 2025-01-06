/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:00:20 by abueskander       #+#    #+#             */
/*   Updated: 2025/01/06 07:17:42 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
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
	pthread_mutex_t			*print;
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
	pthread_mutex_t			*forks;
	pthread_mutex_t			*dead;
	pthread_mutex_t 		*print;
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
void						*routine(void *args);
int							init_threads(t_table *table);
t_timelen					get_time_fixed(void);
int							init_forks(t_table *table);
int							start_threading(t_table *table);
void						clean_destroyes(t_table *table);
int							thinking(t_philosofo *philoso);
int							sleeping(t_philosofo *philoso);
int							am_i_dead(t_philosofo *philoso);
int							eating(t_philosofo *philoso);
void						lock_forks(t_philosofo *philoso);
void						unlock_forks(t_philosofo *philoso);
void						announce_death(t_philosofo *philoso);
t_timelen					actual_sleep(t_timelen time, t_timelen time_to_wait,
								t_philosofo *philoso);

#endif