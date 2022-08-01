/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:27:32 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/01 15:03:59 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

#include <unistd.h>

void	*end_routine(t_philo *philo)
{
	if (philo->nb_forks)
	{
		sem_post(philo->forks);
		philo->nb_forks -= 1;
	}
	if (philo->nb_forks)
	{
		sem_post(philo->forks);
		philo->nb_forks -= 1;
	}
	return (0);
}

void	*routine_solo(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (run_loop(philo))
		log_print(philo, philo->phi_number, philo->start, "is thinking");
	if (run_loop(philo))
		grab_fork(philo);
	while (run_loop(philo))
		usleep (300);
	return (end_routine(philo));
}

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (run_loop(philo))
		log_print(philo, philo->phi_number, philo->start, "is thinking");
	if (philo->phi_number % 2 == 1)
		msleep(philo->phi_const->time_to_eat, timestamp(0), philo);
	if (philo->phi_number % 2 == 1
		&& philo->phi_number == philo->phi_const->nb_philo)
		msleep(philo->phi_const->time_to_eat / 2, timestamp(0), philo);
	while (run_loop(philo))
	{
		if (run_loop(philo))
			grab_fork(philo);
		if (run_loop(philo))
			grab_fork(philo);
		if (run_loop(philo))
			phi_eat(philo);
		if (run_loop(philo))
			phi_sleep(philo);
		if (run_loop(philo))
			phi_think(philo);
	}
	return (end_routine(philo));
}
