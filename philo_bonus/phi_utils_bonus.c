/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:31:08 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/28 20:27:15 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void	msleep(long time, long start)
{
	while (timestamp(start) < (long)time)
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
