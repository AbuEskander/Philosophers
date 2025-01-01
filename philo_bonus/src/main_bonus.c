/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:16:17 by abueskander       #+#    #+#             */
/*   Updated: 2025/01/01 22:12:28 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

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

static int	initilaize_inital_values(t_table *philoso, char **inputs)
{
	philoso->nop = ft_atoi(inputs[NUMBEROFP]);
	philoso->ttd = ft_atoi(inputs[TIMETODIE]);
	philoso->tte = ft_atoi(inputs[TIMETOEAT]);
	philoso->tts = ft_atoi(inputs[TIMETOSLEEP]);
	philoso->who_is_dead = -1;
	philoso->forks = NULL;
	philoso->dead = NULL;
	philoso->wce = NULL;
	philoso->allphiloso = malloc(sizeof(t_philosofo) * philoso->nop);
	if (!philoso->allphiloso)
		return (EXIT_FAILURE);
	if (inputs[NUMBEROFMEALS])
		philoso->nuofm = ft_atoi(inputs[NUMBEROFMEALS]);
	else
		philoso->nuofm = NOMEALCOUNT;
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < MIN_ARGS || argc > MAX_ARGS)
		display_error("Invalid number of arguments");
	if (validate_input(argv))
		return (EXIT_FAILURE);
	if (initilaize_inital_values(&table, argv))
	{
		display_error("Error While initalizing\n");
		return (EXIT_FAILURE);
	}
	if (init_forks(&table) || init_process(&table) || start_processing(&table))
	{
		clean_destroyes(&table,-1);
		perror("ERROR");
	}
	if(table.who_is_dead > 0)
		announce_death(&table.allphiloso[table.who_is_dead -1]);
	clean_destroyes(&table,-1);
	return(EXIT_SUCCESS);
}
