/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_init_table_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:52:00 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/28 21:23:36 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

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

int	init_all_sem(t_table *table, int nb_philo)
{
	table->forks = sem_open(FORKS_SEM, O_CREAT, O_RDWR, nb_philo);
	if (!table->forks)
		return (9);
	table->log = sem_open(LOG_SEM, O_CREAT, O_RDWR, 1);
	if (table->log)
		return (9);
	table->end.value = 0;
	table->end.mut = sem_open(END_SEM, O_CREAT, O_RDWR, 1);
	if (table->end)
		return (9);
	return (0);
}

int	init_table(t_table *table, int nb_philo)
{
	int	error;

	error = set_all_philo(table, nb_philo);
	if (error)
		return (error);
	table->all_thread = malloc(sizeof(pthread_t) * (nb_philo + 1));
	if (!table->all_thread)
		return (free(table->all_philo), 7);
	memset(table->all_thread, 0, sizeof(pthread_t) * (nb_philo + 1));
	error = init_all_sem(table, nb_philo);
	return (error);
}
