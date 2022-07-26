/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:09:07 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/26 19:56:07 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>

#include "philosopher.h"

/*	pthread_mutex_destroy(&table->all_fork[i]);
while (++i < table->phi_const.nb_philo)
*/

void	free_forks(t_table *table)
{
	int	i;

	i = -1;
	free(table->all_fork);
}

static void	free_philo(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->phi_const->nb_philo)
		pthread_mutex_destroy(&(philo[i].last_meal_mut));
	free(philo);
}

void	free_table(t_table *table)
{
	free_forks(table);
	pthread_mutex_destroy(&table->end.mut);
	pthread_mutex_destroy(&table->log);
	free_philo(table->all_philo);
	free(table->all_thread);
}
