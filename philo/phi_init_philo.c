/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_init_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:48:22 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/28 01:20:20 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

pthread_mutex_t	*set_l_fork(int i, int nb_philo, pthread_mutex_t *mut)
{
	(void)nb_philo;
	if (i == 0)
		return (&mut[i]);
	else
		return (&mut[i - 1]);
}

pthread_mutex_t	*set_r_fork(int i, int nb_philo, pthread_mutex_t *mut)
{
	if (i == 0)
		return (&mut[nb_philo - 1]);
	else
		return (&mut[i]);
}

void	init_philo(t_table *table, t_philo *philo, long start, int i)
{
	philo->phi_const = &table->phi_const;
	philo->end = &(table->end);
	philo->end_thread = &(table->end_thread);
	philo->log = &table->log;
	philo->setup = &(table->setup);
	philo->nb_of_meal = 0;
	philo->phi_number = i + 1;
	philo->quota = 0;
	philo->last_meal = 0;
	pthread_mutex_init(&(philo->last_meal_mut), 0);
	philo->start = start;
	philo->l_fork = set_l_fork(i, table->phi_const.nb_philo, table->all_fork);
	philo->r_fork = set_r_fork(i, table->phi_const.nb_philo, table->all_fork);
	philo->take_l_fork = 0;
	philo->take_r_fork = 0;
}
