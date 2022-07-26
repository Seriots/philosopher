/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:31:08 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/26 23:02:16 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void	msleep(unsigned long time)
{
	time = time * 1000;
	usleep((__useconds_t)time);
}

long	timestamp(long start)
{
	struct timeval	time;
	long			time_value;

	if (start == -1)
		return (0);
	gettimeofday(&time, 0);
	time_value = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (time_value - start);
}
