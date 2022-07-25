/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:28:30 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/25 22:12:42 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*end_routine(t_philo *philo)
{
	pthread_mutex_lock(&(philo->end_routine.mut));
	philo->end_routine.end += 1;
	pthread_mutex_unlock(&(philo->end_routine.mut));
	pthread_mutex_lock(&(philo->end_thread->mut));
	philo->end_thread->end += 1;
	pthread_mutex_unlock(&(philo->end_thread->mut));
	if (philo->take_l_fork)
	{
		pthread_mutex_unlock(philo->l_fork);
		philo->take_l_fork = 0;
	}
	if (philo->take_r_fork)
	{
		pthread_mutex_unlock(philo->r_fork);
		philo->take_r_fork = 0;
	}
	return (0);
}

void	*routine(void *args)
{
	t_philo *philo;

	philo = (t_philo *)args;
	while (run_loop(philo))
	{
		log_print(philo, philo->phi_number, philo->start, "is thinking");
		if (run_loop(philo))
			grab_left_fork(philo);
		if (run_loop(philo))
			grab_right_fork(philo);
		if (run_loop(philo))
			phi_eat(philo);
		if (run_loop(philo))
			phi_sleep(philo);
	}
	return (end_routine(philo));
}


/*
* delay
* loop:
* think
* left fork
* right fork
* eat
* sleep
*/