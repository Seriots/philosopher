/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine_action_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:41:42 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/30 18:20:54 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	grab_fork(t_philo *philo)
{
	sem_wait(philo->forks);
	log_print(philo, philo->phi_number, philo->start, "has taken a fork");
	philo->nb_forks += 1;
}

void	phi_eat(t_philo *philo)
{
	int	te;

	te = philo->phi_const->time_to_eat;
	log_print(philo, philo->phi_number, philo->start, "is eating");
	sem_wait(philo->sem_nb_meal);
	philo->nb_of_meal++;
	sem_post(philo->sem_nb_meal);
	msleep(te, timestamp(0));
	sem_post(philo->forks);
	sem_post(philo->forks);
	philo->nb_forks = 0;
}

void	phi_sleep(t_philo *philo)
{
	int	ts;

	ts = philo->phi_const->time_to_sleep;
	log_print(philo, philo->phi_number, philo->start, "is sleeping");
	msleep(ts, timestamp(0));
}
