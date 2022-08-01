/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:41:42 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/01 15:03:17 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	grab_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	philo->take_l_fork = 1;
	log_print(philo, philo->phi_number, philo->start, "has taken a fork");
}

void	grab_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	philo->take_r_fork = 1;
	log_print(philo, philo->phi_number, philo->start, "has taken a fork");
}

void	phi_eat(t_philo *philo)
{
	int	te;

	te = philo->phi_const->time_to_eat;
	log_print(philo, philo->phi_number, philo->start, "is eating");
	msleep(te, timestamp(0), philo);
	philo->take_l_fork = 0;
	philo->take_r_fork = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	philo->nb_of_meal++;
}

void	phi_sleep(t_philo *philo)
{
	int	ts;

	ts = philo->phi_const->time_to_sleep;
	log_print(philo, philo->phi_number, philo->start, "is sleeping");
	msleep(ts, timestamp(0), philo);
}
