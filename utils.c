/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:50:01 by mohamoha          #+#    #+#             */
/*   Updated: 2024/02/13 14:36:19 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if (str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && (str[i]
					- '0') > INT_MAX % 10) || result < 0)
		{
			error_handle("Number is > INT_MAX");
			return (-404);
		}
		result = 10 * result + (str[i] - '0');
		i++;
	}
	return (result);
}

long	get_time_day(t_time time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		error_handle("Gettimeofday error");
	if (SECOND == time)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (MILLISECOND == time)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (MICROSECOND == time)
		return ((tv.tv_sec * 1e6) + (tv.tv_usec));
	else
		error_handle("Wrong time");
	return (404);
}

void	ft_usleep(long usec, t_data *data)
{
	long	start;
	long	elapse;
	long	rem;

	start = get_time_day(MICROSECOND);
	while (get_time_day(MICROSECOND) - start < usec)
	{
		if (rotuine_finished(data))
			break ;
		elapse = get_time_day(MICROSECOND) - start;
		rem = usec - elapse;
		if (rem > 1e3)
			usleep(rem / 2);
		else
		{
			while (get_time_day(MICROSECOND) - start < usec)
				;
		}
	}
}
