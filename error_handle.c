/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:07:47 by mohamoha          #+#    #+#             */
/*   Updated: 2023/12/28 10:40:47 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_handle(char **av, char *msg)
{
	if (msg)
		write(1, msg, ft_strlen(msg));
	if (av)
		free_string(av);
	exit(EXIT_FAILURE);
}

void	free_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
