/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:59:24 by mohamoha          #+#    #+#             */
/*   Updated: 2024/01/21 13:51:00 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	parse_args(t_data *data, char **av)
{
	int	i;

	if (!av)
		return ;
	i = 1;
	while (av[i])
	{
		if (av[i][0] == '\0' || is_valid_number(av[i]) == 1)
			error_handle("Error, invalid arguments");
		i++;
	}
	data->philo_num = ft_atoi(av[1]);
	data->t_to_die = ft_atoi(av[2]) * 1e3;
	data->t_to_eat = ft_atoi(av[3]) * 1e3;
	data->t_to_sleep = ft_atoi(av[4]) * 1e3;
	if (data->t_to_die < 60e3
		|| data->t_to_eat < 60e3
			|| data->t_to_sleep < 60e3)
			error_handle("Timestamp should be > 60ms");
	if (av[5])
		data->num_meals_limit = ft_atoi(av[5]);
	else
		data->num_meals_limit = -1;
}
