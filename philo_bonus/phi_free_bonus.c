/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_free_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:09:07 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/28 20:34:05 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>

#include "philosopher_bonus.h"

/*	pthread_mutex_destroy(&table->all_fork[i]);
while (++i < table->phi_const.nb_philo)
*/

static void	free_philo(t_philo *philo)
{
	free(philo);
}

void	free_table(t_table *table)
{
	free_philo(table->all_philo);
	free(table->all_thread);
}
