/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:09:07 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/24 20:30:51 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>

#include "philosopher.h"

void	free_forks(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->phi_const.nb_philo)
		pthread_mutex_destroy(&table->all_fork[i]);
	free(table->all_fork);
}

void	free_table(t_table *table)
{
	free_forks(table);
	pthread_mutex_destroy(&table->end.mut);
	pthread_mutex_destroy(&table->log);
	free(table->all_philo);
}
