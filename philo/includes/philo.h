/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:00:20 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/19 20:20:09 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define MAX_ARGS 6
# define MIN_ARGS 5

typedef struct s_philoso
{
        int     nop;
        int     tts;
        int     ttd;
        int     tte;
}       t_philoso;

enum    e_inputs
{
        NUMBEROFP = 1,
        TIMETODIE,
        TIMETOEAT,
        TIMETOSLEEP,
        NUMBEROFMEALS
};
void	display_error(char *str);
void	ft_putstr(char *str, int fd);
int		ft_atoi(const char *nptr);
int		check_number(char *item);
int		check_numbers(char **number);
int		onlydigits(char *str);
size_t	ft_strlen(char *str);
size_t	total_len(ssize_t n);

#endif