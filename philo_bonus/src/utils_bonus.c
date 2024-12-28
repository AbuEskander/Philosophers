/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:50:04 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/28 22:59:27 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

size_t	total_len(ssize_t n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while ((n != 0))
	{
		n /= 10;
		len++;
	}
	return (len);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

long	ft_atoi(const char *nptr)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*nptr == 32 || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*(nptr++) == '-')
			sign = -1;
	while (*nptr && *nptr >= '0' && *nptr <= '9')
		res = res * 10 + *(nptr++) - '0';
	return (res * sign);
}

int	onlydigits(char *str)
{
	int	tmp;

	tmp = ft_atoi(str);
	if (total_len(tmp) != ft_strlen(str))
		return (1);
	if (tmp == 0)
		if (*str != '0')
			return (1);
	return (0);
}
