/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:54:44 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/28 22:55:06 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	check_number(char *item)
{
	if (ft_atoi(item) <= 0 || onlydigits(item))
	{
		display_error("Invalid Input ");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_numbers(char **number)
{
	int	num;

	num = 1;
	while (num <= 4)
		if (check_number(number[num++]))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
