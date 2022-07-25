/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:31:08 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/25 22:30:13 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) != 0 && *(s2 + i) != 0 && *(s1 + i) == *(s2 + i))
		i++;
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}

void	log_print(t_philo *philo, int phi_num, long start, char *message)
{
	pthread_mutex_lock(philo->log);
	pthread_mutex_lock(&(philo->end->mut));
	if (!philo->end->end)
		printf("%li %d %s\n", timestamp(start), phi_num, message);
	pthread_mutex_unlock(philo->log);
	if (!ft_strcmp(message, "died"))
		philo->end->end = 1;
	pthread_mutex_unlock(&(philo->end->mut));
}

void	log_print_main(t_table *table, int phi_num, long start, char *message)
{
	pthread_mutex_lock(&(table->log));
	printf("%li -%li- %d %s\n", timestamp(start), start, phi_num, message);
	pthread_mutex_unlock(&(table->log));
}

void	msleep(unsigned long time)
{
	time = time * 1000;
	usleep((__useconds_t)time);
}

long	timestamp(long start)
{
	struct timeval	time;
	long			time_value;

	if (start == 0)
		return (0);
	gettimeofday(&time, 0);
	time_value = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (time_value - start);
}