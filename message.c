/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:00:23 by mohamoha          #+#    #+#             */
/*   Updated: 2024/01/21 13:13:07 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_status_debug(t_philo_status status, t_philo *philo, long elapsed)
{
	if (TAKE_FIRST_FORK == status && !rotuine_finished(philo->data))
		printf(W"%6ld"RST" %d has taken the 1° fork 🍽"
			"\t\t\tn°"B"[🍴 %d 🍴]\n"RST, elapsed, philo->id,
			philo->first_fork->fork_id);
	else if (TAKE_SECOND_FORK == status && !rotuine_finished(philo->data))
		printf(W"%6ld"RST" %d has taken the 2° fork 🍽"
			"\t\t\tn°"B"[🍴 %d 🍴]\n"RST, elapsed, philo->id,
			philo->second_fork->fork_id);
	else if (EATING == status && !rotuine_finished(philo->data))
		printf(W"%6ld"C" %d is eating 🍝"
			"\t\t\t"Y"[🍝 %ld 🍝]\n"RST, elapsed, philo->id, philo->meals_count);
	else if (SLEEPING == status && !rotuine_finished(philo->data))
		printf(W"%6ld"RST" %d is sleeping 😴\n", elapsed, philo->id);
	else if (THINKING == status && !rotuine_finished(philo->data))
		printf(W"%6ld"RST" %d is thinking 🤔\n", elapsed, philo->id);
	else if (DIED == status)
		printf(RED"\t\t💀💀💀 %6ld %d died   💀💀💀\n"RST, elapsed, philo->id);
}

void	philo_status(t_philo_status	status, t_philo	*philo, bool bug_check)
{
	long	elapsed;

	elapsed = get_time_day(MILLISECOND) - philo->data->start_routine;
	if (philo->full)
		return ;
	mutex_handler(&philo->data->status_mutex, LOCK);
	if (bug_check)
		philo_status_debug(status, philo, elapsed);
	else
	{
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
			printf("%-6ld"" %d died\n", elapsed, philo->id);;
	}
	mutex_handler(&philo->data->status_mutex, UNLOCK);
}
