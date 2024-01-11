/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:46:55 by mohamoha          #+#    #+#             */
/*   Updated: 2024/01/10 19:12:42 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data, char **av)
{
	if (!av)
		return ;
	data->philo_num = ft_atoi(av[1]);
	data->t_to_die = ft_atoi(av[2]);
	data->t_to_eat = ft_atoi(av[3]);
	data->t_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->num_meals_limit = ft_atoi(av[5]);
	else
		data->num_meals_limit = -1;
}
