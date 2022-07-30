/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_init_philo_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:48:22 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/30 18:50:09 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

#include <stdio.h>

void	init_philo(t_table *table, t_philo *philo, long start, int i)
{
	philo->phi_const = &table->phi_const;
	philo->nb_of_meal = 0;
	philo->phi_number = i + 1;
	philo->last_meal = 0;
	philo->start = start;
	philo->forks = table->forks;
	philo->nb_forks = 0;
	philo->log = table->log;
	philo->sem_last_meal = table->sem_last_meal;
	philo->sem_nb_meal = table->sem_nb_meal;
	philo->end = &table->end;
}