/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine_loop_cond_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:57:31 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/30 16:08:23 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	run_loop(t_philo *philo)
{
	sem_wait(philo->end->mut);
	if (philo->end->value)
		return (sem_post(philo->end->mut), 0);	
	return (sem_post(philo->end->mut), 1);
}
