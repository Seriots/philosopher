/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine_loop_cond.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:57:31 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/02 22:32:29 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	run_loop(t_philo *philo)
{
	pthread_mutex_lock(&(philo->end->mut));
	if (philo->end->end == 1 || philo->phi_const->nb_repeat == 0)
		return (pthread_mutex_unlock(&(philo->end->mut)), 0);
	pthread_mutex_unlock(&(philo->end->mut));
	pthread_mutex_lock(&(philo->last_meal_mut));
	if (timestamp(philo->start) - philo->last_meal
		>= (long)philo->phi_const->time_to_die)
		return (pthread_mutex_unlock(&(philo->last_meal_mut)), 0);
	pthread_mutex_unlock(&(philo->last_meal_mut));
	if (philo->phi_const->nb_repeat == -1)
		return (1);
	if (philo->nb_of_meal >= philo->phi_const->nb_repeat && philo->quota == 0)
	{
		pthread_mutex_lock(&(philo->end_thread->mut));
		philo->end_thread->end += 1;
		pthread_mutex_unlock(&(philo->end_thread->mut));
		philo->quota = 1;
	}
	return (1);
}
