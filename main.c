/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:58:18 by mohamoha          #+#    #+#             */
/*   Updated: 2024/01/21 14:25:21 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (5 == ac || 6 == ac)
	{
		parse_args(&data, av);
		init_data(&data);
		routine_start(&data);
		clean_exit(&data);
	}
	else
		error_handle("Error, invalid Number of arguments");
}
