/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:44:15 by mohamoha          #+#    #+#             */
/*   Updated: 2024/01/18 18:56:09 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_dinner(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->data);

	
	while (!rotuine_finished(philo->data))
	{
		if (full)
			break ;
		eating();
		
		thinking();

		sleeping();
		
	}


	
	return (NULL);
}

 void   routine_start(t_data *data)
 {
	int	i;

	i = 0;
    if (0 == data->num_meals_limit)
        return ;
    else if (1 == data->philo_num)
	{
		//implement
	}
    else
	{
		while (i < data->philo_num)
			thread_handle(&data->philos[i].thread_id, routine_dinner,
				&data->philos[i], CREATE);
	}
	data->start_routine = get_time_day(MILLISECOND);
	
	set_bool(&data->data_mutex, &data->all_threads_ready, true);
	i = 0;
	while (i < data->philo_num)
	{
		thread_handle(&data->philos[i].thread_id, NULL, NULL, JOIN);
		i++;
	}
}
