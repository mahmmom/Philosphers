/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:59:24 by mohamoha          #+#    #+#             */
/*   Updated: 2024/01/10 19:13:33 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	parse_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '\0' || is_valid_number(av[i]) == 1)
			error_handle(NULL, "Error, invalid arguments\n");
		i++;
	}
}
