/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:07:47 by mohamoha          #+#    #+#             */
/*   Updated: 2024/02/03 18:35:54 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_handle(char *msg)
{
	if (msg)
		printf("%s\n", msg);
	return ;
}

void	clean_exit(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < data->philo_num)
	{
		philo = data->philos + i;
		mutex_handler(&philo->pilo_mutex, DESTROY);
		i++;
	}
	mutex_handler(&data->status_mutex, DESTROY);
	mutex_handler(&data->data_mutex, DESTROY);
	free(data->forks);
	free(data->philos);
}
