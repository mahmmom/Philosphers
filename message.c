/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:00:23 by mohamoha          #+#    #+#             */
/*   Updated: 2024/02/03 18:41:35 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_status(t_philo_status	status, t_philo	*philo)
{
	long	elapsed;

	elapsed = get_time_day(MILLISECOND) - philo->data->start_routine;
	if (philo->full)
		return ;
	mutex_handler(&philo->data->status_mutex, LOCK);
	if (((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
			&& !rotuine_finished(philo->data)))
		printf("%-6ld"" %d has taken a fork\n", elapsed, philo->id);
	else if (EATING == status && !rotuine_finished(philo->data))
		printf("%-6ld"" %d is eating\n", elapsed, philo->id);
	else if (SLEEPING == status && !rotuine_finished(philo->data))
		printf("%-6ld"" %d is sleeping\n", elapsed, philo->id);
	else if (THINKING == status && !rotuine_finished(philo->data))
		printf("%-6ld"" %d is thinking\n", elapsed, philo->id);
	else if (DIED == status)
		printf("%-6ld"" %d died\n", elapsed, philo->id);
	mutex_handler(&philo->data->status_mutex, UNLOCK);
}
