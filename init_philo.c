/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:46:55 by mohamoha          #+#    #+#             */
/*   Updated: 2024/01/21 16:12:43 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*malloc_handler(size_t bytes)
{
	void	*temp;

	temp = malloc(bytes);
	if (NULL == temp)
		error_handle("Malloc Error");
	return (temp);
}

static void	assign_forks(t_philo *philo, t_fork *forks, int philo_pos)
{
	int	philo_num;

	philo_num = philo->data->philo_num;
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[philo_pos];
		philo->second_fork = &forks[(philo_pos + 1) % philo_num];
	}
	else
	{
		philo->second_fork = &forks[philo_pos];
		philo->first_fork = &forks[(philo_pos + 1) % philo_num];
	}
}

static void	init_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < data->philo_num)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_count = 0;
		mutex_handler(&philo->pilo_mutex, INIT);
		philo->data = data;
		assign_forks(philo, data->forks, i);
	}
}

void	init_data(t_data *data)
{
	int	i;

	i = -1;
	data->end_routine = false;
	data->all_threads_ready = false;
	data->running_threads_num = 0;
	data->philos = malloc_handler(sizeof(t_philo) * data->philo_num);
	data->forks = malloc_handler(sizeof(t_fork) * data->philo_num);
	mutex_handler(&data->status_mutex, INIT);
	mutex_handler(&data->data_mutex, INIT);
	while (++i < data->philo_num)
	{
		mutex_handler(&data->forks[i].fork, INIT);
		data->forks[i].fork_id = i;
	}
	init_philo(data);
}
