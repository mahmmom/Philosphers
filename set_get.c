/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:43:51 by mohamoha          #+#    #+#             */
/*   Updated: 2024/01/16 19:08:40 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(t_mutx *mutex, bool *dest, bool value)
{
	mutex_handler(mutex, LOCK);
	*dest = value;
	mutex_handler(mutex, UNLOCK);
}

bool	get_bool(t_mutx *mutex, bool *value)
{
	bool	ret;

	mutex_handler(mutex, LOCK);
	ret = *value;
	mutex_handler(mutex, UNLOCK);
	return (ret);
}

void	set_long(t_mutx *mutex, long *dest, long value)
{
	mutex_handler(mutex, LOCK);
	*dest = value;
	mutex_handler(mutex, UNLOCK);
}

long	get_long(t_mutx *mutex, long *value)
{
	long	ret;

	mutex_handler(mutex, LOCK);
	ret = *value;
	mutex_handler(mutex, UNLOCK);
	return (ret);
}

bool	rotuine_finished(t_data	*data)
{
	return (get_bool(&data->data_mutex, &data->end_routine));
}
