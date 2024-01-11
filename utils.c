/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:50:01 by mohamoha          #+#    #+#             */
/*   Updated: 2024/01/10 19:15:25 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*is_valid(char *str)
{
	int		i;
	int		len;
	char	*validated;
	
	i = 0;
	len = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
		error_handle(NULL, "Only Positive Numbers Allowed\n");
	validated = str;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		len++;
	}
	// if (len > 10)
	// 	error_handle(NULL, "Number shouldn't be > INT_MAX\n");
	return (validated);
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;
	
	result = 0;
	i = 0;
	str = is_valid(str);
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		result = 10 * result + (str[i] - '0');
		i++;
	}
	if (result < 0)
		error_handle(NULL, "Number is > INT_MAX\n");
	return (result);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}