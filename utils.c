/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:50:01 by mohamoha          #+#    #+#             */
/*   Updated: 2024/01/18 18:59:29 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*is_valid(char *str)
{
	int		i;
	int		len;
	char	*validated;
	
	i = 0;
	len = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
		error_handle("Only Positive Numbers Allowed");
	validated = str;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		len++;
	}
	return (validated);
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;
	
	result = 0;
	i = 0;
	str = is_valid(str);
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		result = 10 * result + (str[i] - '0');
		i++;
	}
	if (result < 0)
		error_handle("Number is > INT_MAX");
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
		return (error_handle("Wrong time"),0);
	//return (404);
}

void	ft_usleep()
{
	
}