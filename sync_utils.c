/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:01:49 by mohamoha          #+#    #+#             */
/*   Updated: 2024/02/08 18:02:43 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_all_threads(t_data *data)
{
	while (!get_bool(&data->data_mutex, &data->all_threads_ready))
		;
}

bool	all_threads_running(t_mutx	*mutex, long *threads, long philo_num)
{
	bool	ret;

	ret = false;
	mutex_handler(mutex, LOCK);
	if (*threads == philo_num)
		ret = true;
	mutex_handler(mutex, UNLOCK);
	return (ret);
}

void	increase_long(t_mutx *data_mutex, long	*threads_num)
{
	mutex_handler(data_mutex, LOCK);
	(*threads_num)++;
	mutex_handler(data_mutex, UNLOCK);
}

void	de_sync(t_philo	*philo)
{
	if (philo->data->philo_num % 2 == 0)
	{
		if (philo->id % 2 == 0)
			ft_usleep(3e4, philo->data);
	}
	else
	{
		if (philo->id % 2)
			thinking_routine(philo, true);
	}
}
