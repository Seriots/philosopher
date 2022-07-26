/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:28:30 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/26 19:55:24 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*end_routine(t_philo *philo)
{
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
	pthread_mutex_lock(&(philo->end_thread->mut));
	philo->end_thread->end += 1;
	pthread_mutex_unlock(&(philo->end_thread->mut));
	return (0);
}

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	log_print(philo, philo->phi_number, philo->start, "is thinking");
	if (philo->phi_number % 2 == 1)
		msleep(philo->phi_const->time_to_eat);
	while (run_loop(philo))
	{
		if (philo->phi_number % 2 == 1
			&& philo->phi_number == philo->phi_const->nb_philo)
			msleep(philo->phi_const->time_to_eat / 2);
		if (run_loop(philo))
			grab_left_fork(philo);
		if (run_loop(philo))
			grab_right_fork(philo);
		if (run_loop(philo))
			phi_eat(philo);
		if (run_loop(philo))
			phi_sleep(philo);
		if (run_loop(philo))
			log_print(philo, philo->phi_number, philo->start, "is thinking");
	}
	return (end_routine(philo));
}
