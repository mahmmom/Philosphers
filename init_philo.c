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
#include <pthread.h>

void	*malloc_handler(size_t	bytes)
{
	void	*temp;

	temp = malloc(bytes);
	if (NULL == temp)
		error_handle("Malloc Error");
	return (temp);
}

static 

void	mutex_error_handler(t_mutx	*mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		pthread_mutex_lock(mutex);
	else if (LOCK == opcode)
		pthread_mutex_unlock(mutex);
	else if (LOCK == opcode)
		pthread_mutex_init(mutex, NULL);
	else if (LOCK == opcode)
		pthread_mutex_destroy(mutex);
	else
		pthread_mutex_lock(mutex);
}

void	init_philo(t_data	*data)
{
	data->end_experiment = false;
	data->philos = malloc_handler(data->philo_num);
}
