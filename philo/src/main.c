/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:56:54 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/26 20:59:57 by abueskander      ###   ########.fr       */
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

static void	initilaize_inital_values(t_table *philoso, char **inputs)
{
	philoso->nop = ft_atoi(inputs[NUMBEROFP]);
	philoso->ttd = ft_atoi(inputs[TIMETODIE]);
	philoso->tte = ft_atoi(inputs[TIMETOEAT]);
	philoso->tts = ft_atoi(inputs[TIMETOSLEEP]);
	philoso->who_is_dead = -1;
	if (inputs[NUMBEROFMEALS])
		philoso->nuofm = ft_atoi(inputs[NUMBEROFMEALS]);
	else
		philoso->nuofm = NOMEALCOUNT;
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < MIN_ARGS || argc > MAX_ARGS)
		display_error("Invalid number of arguments");
	if (validate_input(argv))
		return (EXIT_FAILURE);
	initilaize_inital_values(&table, argv);
	if (init_forks(&table))
		return (EXIT_FAILURE);
	init_threads(&table);
	start_threading(&table);
	if (table.who_is_dead != -1)
		announce_death(&table.allphiloso[table.who_is_dead - 1]);
	clean_destroyes(&table);
	return (EXIT_SUCCESS);
}
