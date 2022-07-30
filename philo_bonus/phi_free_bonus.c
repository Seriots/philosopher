/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_free_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:09:07 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/30 19:35:10 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#include "philosopher_bonus.h"

static void	free_philo(t_philo *philo)
{
	free(philo);
}

void	unlink_sem(void)
{
	sem_unlink(LOG_SEM);
	sem_unlink(FORKS_SEM);
	sem_unlink(END_SEM);
	sem_unlink(MEAL_SEM);
	sem_unlink(NB_MEAL_SEM);
}

void	free_table(t_table *table)
{
	free_philo(table->all_philo);
	free(table->all_thread);
	unlink_sem();
	sem_close(table->log);
	sem_close(table->forks);
	sem_close(table->end.mut);
	sem_close(table->sem_last_meal);
	sem_close(table->sem_nb_meal);
}
