/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:04:56 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/28 19:51:06 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "philosopher.h"

static void	phi_display_parsing_error(int key)
{
	if (key == 1)
		write(2, "Too much Arguments\n", 20);
	else if (key == 2)
		write(2, "Less than four arguments\n", 26);
	else if (key == 3)
		write(2, "Arguments must be positive numbers\n", 36);
	write(2, "Usage: ./philo <numbers_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n", 130);
}

void	phi_display_error(int key)
{
	if (key < 4)
		phi_display_parsing_error(key);
	else if (key == 4)
		write(2, "Too much philosopher, (max: 200)\n", 33);
	else if (key == 5)
		write(2, "A minimum of one philosophers is needed\n", 41);
	else if (key == 6)
		write(2, "Arguments overflow\n", 20);
	else if (key == 7)
		write(2, "Malloc error\n", 14);
	else if (key == 8)
		write(2, "Thread error\n", 14);
}

int	thread_creation_error(t_table *table, int error)
{
	pthread_mutex_lock(&(table->end.mut));
	table->end.end = 1;
	pthread_mutex_unlock(&(table->end.mut));
	wait_all_thread(table);
	return (phi_display_error(error), free_table(table), 1);
}
