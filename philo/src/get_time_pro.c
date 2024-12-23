/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_pro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:30:59 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/23 22:41:10 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

size_t      get_time_fixed(void)
{
        struct timeval time;
        size_t  current_time;
        gettimeofday(&time,NULL);

        current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
        return (current_time);
} 