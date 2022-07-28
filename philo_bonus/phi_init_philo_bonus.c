/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_init_philo_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:48:22 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/28 21:19:39 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	init_philo(t_table *table, t_philo *philo, long start, int i)
{
	philo->phi_const = &table->phi_const;
	philo->nb_of_meal = 0;
	philo->phi_number = i + 1;
	philo->last_meal = 0;
	philo->start = start;
	philo->forks = table->forks;
	philo->log = table->log;
	philo->end = &table->end;
}
