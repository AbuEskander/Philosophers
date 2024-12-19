/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:56:54 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/19 19:30:12 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	validate_input(char **input)
{
	check_numbers(input);
	if (input[5] && (ft_atoi(input[5]) < 0 || onlydigits(input[5])))
	{
		display_error("Invalid Input");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc < MIN_ARGS || argc > MAX_ARGS)
		display_error("Invalid number of arguments");
	if (validate_input(argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
