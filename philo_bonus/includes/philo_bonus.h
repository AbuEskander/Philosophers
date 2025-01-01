/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:15:00 by abueskander       #+#    #+#             */
/*   Updated: 2025/01/01 18:37:23 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <fcntl.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>
# define MAX_ARGS 6
# define MIN_ARGS 5
# define NOMEALCOUNT -1
# define DEATH "dead"
# define FORKS "FORKS"
# define WHO_CAN_EAT "BATATA"
typedef unsigned long long	t_timelen;

typedef struct s_philosopho
{
	int						id;
	pid_t						child_id;
	pthread_t				tid;
	int						tts;
	int						ttd;
	int						tte;
	int						nuofm;
	t_timelen				sim_start;
	t_timelen				wokeup;
	t_timelen				last_meal;
	sem_t			*forks;
	sem_t			*death;
	sem_t			*wce;
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
	sem_t			*wce;
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
int	eating(t_philosofo *philoso);
int	sleeping(t_philosofo *philoso);
int     thinking (t_philosofo *philoso);
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
int	init_forks(t_table *table);
void	clean_destroyes(t_table *table,int pid);
int	start_processing(t_table *table);
void     lock_forks(t_philosofo *philoso);
void     unlock_forks(t_philosofo *philoso);
t_timelen	actual_sleep(t_timelen time, t_timelen time_to_wait,
		t_philosofo *philoso);
void    routine(t_philosofo *philoso);
int     am_i_dead_bonus(t_philosofo *philoso);
void	announce_death(t_philosofo *philoso);

#endif