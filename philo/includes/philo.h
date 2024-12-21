/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:00:20 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/21 12:45:49 by abueskander      ###   ########.fr       */
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

typedef struct s_philosopho
{
	int				id;
	pthread_t		tid;
	int				tts;
	int				ttd;
	int				tte;
	int				nuofm;

}					t_philosofo;

typedef struct s_table
{
	int				nop;
	int				tts;
	int				ttd;
	int				tte;
	int				nuofm;
	t_philosofo		*allphiloso;
	pthread_mutex_t	*mutexs;

}					t_table;

enum				e_inputs
{
	NUMBEROFP = 1,
	TIMETODIE,
	TIMETOEAT,
	TIMETOSLEEP,
	NUMBEROFMEALS
};
void				display_error(char *str);
void				ft_putstr(char *str, int fd);
int					ft_atoi(const char *nptr);
int					check_number(char *item);
int					check_numbers(char **number);
int					onlydigits(char *str);
size_t				ft_strlen(char *str);
size_t				total_len(ssize_t n);
void				*routine(void *args);
int					init_threads(t_table *table);

#endif