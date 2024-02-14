/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:00:23 by mohamoha          #+#    #+#             */
/*   Updated: 2024/02/13 19:16:59 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_status(t_philo_status status, t_philo *philo)
{
	long	elapsed;

	elapsed = get_time_day(MILLISECOND) - philo->data->start_routine;
	if (philo->full)
		return ;
	mutex_handler(&philo->data->status_mutex, LOCK);
	if (((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
			&& !rotuine_finished(philo->data)))
		printf("%-6ld%s %d has taken a fork 🍴%s\n", elapsed, Y, philo->id, RST);
	else if (EATING == status && !rotuine_finished(philo->data))
		printf("%-6ld%s %d is eating 🍔%s\n", elapsed, G, philo->id, RST);
	else if (SLEEPING == status && !rotuine_finished(philo->data))
		printf("%-6ld%s %d is sleeping 😴%s\n", elapsed, B, philo->id, RST);
	else if (THINKING == status && !rotuine_finished(philo->data))
		printf("%-6ld%s %d is thinking 🤔%s\n", elapsed, M, philo->id, RST);
	else if (DIED == status)
		printf("%-6ld%s %d died 💀%s\n", elapsed, RED, philo->id, RST);
	mutex_handler(&philo->data->status_mutex, UNLOCK);
}
