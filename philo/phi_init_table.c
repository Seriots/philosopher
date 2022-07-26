/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_init_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:52:00 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/28 19:32:15 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

static int	set_all_philo(t_table *table, int nb_philo)
{
	int				i;
	struct timeval	start;
	long			start_value;

	i = 0;
	table->all_philo = malloc(sizeof(t_philo) * (nb_philo + 1));
	if (!table->all_philo)
		return (7);
	memset(table->all_philo, 0, sizeof(t_philo) * (nb_philo + 1));
	gettimeofday(&start, 0);
	start_value = start.tv_sec * 1000 + start.tv_usec / 1000;
	table->start = start_value;
	while (i < nb_philo)
	{
		init_philo(table, &table->all_philo[i], start_value, i);
		i ++;
	}
	return (0);
}	

static int	init_all_fork(t_table *table, int nb_philo)
{
	int	i;

	i = 0;
	table->all_fork = malloc(sizeof(pthread_mutex_t) * (nb_philo + 1));
	if (!table->all_fork)
		return (7);
	memset(table->all_fork, 0, sizeof(pthread_mutex_t) * (nb_philo + 1));
	while (i < nb_philo)
	{
		pthread_mutex_init(&table->all_fork[i], 0);
		i ++;
	}
	return (0);
}

int	init_table(t_table *table, int nb_philo)
{
	int	error;

	error = init_all_fork(table, nb_philo);
	if (error)
		return (error);
	error = set_all_philo(table, nb_philo);
	if (error)
		return (free_forks(table), error);
	table->all_thread = malloc(sizeof(pthread_t) * (nb_philo + 1));
	if (!table->all_thread)
		return (free_forks(table), free(table->all_philo), 7);
	memset(table->all_thread, 0, sizeof(pthread_t) * (nb_philo + 1));
	pthread_mutex_init(&table->log, 0);
	pthread_mutex_init(&table->end.mut, 0);
	table->end.end = 0;
	pthread_mutex_init(&table->end_thread.mut, 0);
	table->end_thread.end = 0;
	pthread_mutex_init(&table->setup, 0);
	return (0);
}
