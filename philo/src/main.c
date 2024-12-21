/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:56:54 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/19 20:37:17 by abueskander      ###   ########.fr       */
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
static void     initilaize_inital_values(t_philoso *philoso, char **inputs)
{
        philoso->nop = ft_atoi(inputs[NUMBEROFP]);
        philoso->ttd = ft_atoi(inputs[TIMETODIE]);
        philoso->tte = ft_atoi(inputs[TIMETOEAT]);
        philoso->tts = ft_atoi(inputs[TIMETOSLEEP]);
        
}
int	main(int argc, char **argv)
{
        t_philoso philodef;
        
	if (argc < MIN_ARGS || argc > MAX_ARGS)
		display_error("Invalid number of arguments");
	if (validate_input(argv))
		return (EXIT_FAILURE);
        initilaize_inital_values(&philodef,argv);
        
	return (EXIT_SUCCESS);
}
