/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:31:08 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/01 15:01:52 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void	msleep_main(long time, long start)
{
	while (timestamp(start) < (long)time)
		usleep(300);
}

void	msleep(long time, long start, t_philo *philo)
{
	while (timestamp(start) < (long)time && run_loop(philo))
		usleep(300);
}

long	timestamp(long start)
{
	struct timeval	time;
	long			time_value;

	gettimeofday(&time, 0);
	time_value = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (time_value - start);
}
