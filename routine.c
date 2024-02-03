/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:44:15 by mohamoha          #+#    #+#             */
/*   Updated: 2024/02/03 18:45:59 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	*one_philo(void	*one_philo)
{
	t_philo	*philo;

	philo = (t_philo *)one_philo;
	wait_all_threads(philo->data);
	set_long(&philo->pilo_mutex, &philo->last_meal_time,
		get_time_day(MILLISECOND));
	increase_long(&philo->data->data_mutex, &philo->data->running_threads_num);
	philo_status(TAKE_FIRST_FORK, philo);
	while (!rotuine_finished(philo->data))
		ft_usleep(200, philo->data);
	return (NULL);
}

void	thinking_routine(t_philo *philo, bool pre_routine)
{
	long	t_think;

	if (!pre_routine)
		philo_status(THINKING, philo);
	if (philo->data->philo_num % 2 == 0)
		return ;
	t_think = (philo->data->t_to_eat * 2) - philo->data->t_to_sleep;
	if (t_think < 0)
		t_think = 0;
	ft_usleep(t_think * 0.42, philo->data);
}

static void	eating_routine(t_philo	*philo)
{
	mutex_handler(&philo->first_fork->fork, LOCK);
	philo_status(TAKE_FIRST_FORK, philo);
	mutex_handler(&philo->second_fork->fork, LOCK);
	philo_status(TAKE_SECOND_FORK, philo);
	set_long(&philo->pilo_mutex, &philo->last_meal_time,
		get_time_day(MILLISECOND));
	philo->meals_count++;
	philo_status(EATING, philo);
	ft_usleep(philo->data->t_to_eat, philo->data);
	if (philo->data->num_meals_limit > 0
		&& philo->meals_count == philo->data->num_meals_limit)
		set_bool(&philo->pilo_mutex, &philo->full, true);
	mutex_handler(&philo->first_fork->fork, UNLOCK);
	mutex_handler(&philo->second_fork->fork, UNLOCK);
}

void	*routine_dinner(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->data);
	set_long(&philo->pilo_mutex, &philo->last_meal_time,
		get_time_day(MILLISECOND));
	increase_long(&philo->data->data_mutex,
		&philo->data->running_threads_num);
	de_sync(philo);
	while (!rotuine_finished(philo->data))
	{
		if (philo->full)
			break ;
		eating_routine(philo);
		philo_status(SLEEPING, philo);
		ft_usleep(philo->data->t_to_sleep, philo->data);
		thinking_routine(philo, false);
	}
	return (NULL);
}

void	routine_start(t_data *data)
{
	int	i;

	i = -1;
	if (0 == data->num_meals_limit)
	{
		printf("%-6d"" %d has taken a fork\n", 0, data->philos->id);
		return ;
	}
	else if (1 == data->philo_num)
		thread_handle(&data->philos[0].thread_id, one_philo,
			&data->philos[0], CREATE);
	else
		while (++i < data->philo_num)
			thread_handle(&data->philos[i].thread_id, routine_dinner,
				&data->philos[i], CREATE);
	thread_handle(&data->monitor, monitor_routine, data, CREATE);
	data->start_routine = get_time_day(MILLISECOND);
	set_bool(&data->data_mutex, &data->all_threads_ready, true);
	i = -1;
	while (++i < data->philo_num)
		thread_handle(&data->philos[i].thread_id, NULL, NULL, JOIN);
	set_bool(&data->data_mutex, &data->end_routine, true);
	thread_handle(&data->monitor, NULL, NULL, JOIN);
}
