/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:37:02 by mohamoha          #+#    #+#             */
/*   Updated: 2024/02/03 18:40:09 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_died(t_philo	*philo)
{
	long	elapsed;
	long	time_to_die;

	if (get_bool(&philo->pilo_mutex, &philo->full))
		return (false);
	elapsed = get_time_day(MILLISECOND) - get_long(&philo->pilo_mutex,
			&philo->last_meal_time);
	time_to_die = philo->data->t_to_die / 1e3;
	if (elapsed >= time_to_die)
		return (true);
	return (false);
}

void	*monitor_routine(void	*table)
{
	t_data	*data;
	int		i;

	data = (t_data *)table;
	while (!all_threads_running(&data->data_mutex, &data->running_threads_num,
			data->philo_num))
		;
	while (!rotuine_finished(data))
	{
		i = 0;
		while (i < data->philo_num)
		{
			if (philo_died(data->philos + i) && !rotuine_finished(data))
			{
				set_bool(&data->data_mutex, &data->end_routine, true);
				philo_status(DIED, data->philos + i);
			}
			i++;
		}
	}
	return (NULL);
}
