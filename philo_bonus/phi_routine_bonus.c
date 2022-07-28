/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:27:32 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/28 20:29:18 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void *routine(void *args)
{
	t_philo *philo;
	
	philo = (t_philo *)args;
	log_print(philo, philo->phi_number, philo->start, "live");
	return (0);
}