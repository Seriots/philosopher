/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine_loop_cond.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:57:31 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/25 20:07:05 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	run_loop(t_philo *philo)
{
	pthread_mutex_lock(&(philo->end->mut));
	if (philo->end->end == 1)
		return (pthread_mutex_unlock(&(philo->end->mut)), 0);
	pthread_mutex_unlock(&(philo->end->mut));
	if (philo->phi_const->nb_repeat == -1)
		return (1);
	if (philo->nb_of_meal >= philo->phi_const->nb_repeat)
		return (0);
	return (1);
}