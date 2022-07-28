/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_create_thread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:05:55 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/28 19:45:55 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

#include <pthread.h>

static pthread_t	create_thread(t_philo *philo)
{
	pthread_t	phi_thread;
	int			error;

	phi_thread = 0;
	if (philo->phi_const->nb_philo == 1)
		error = pthread_create(&phi_thread, 0, routine_solo, philo);
	else
		error = pthread_create(&phi_thread, 0, routine, philo);
	if (error)
		return (0);
	return (phi_thread);
}

int	create_all_thread(pthread_t	*all_thread, t_philo *all_philo, int nb_philo)
{
	pthread_t	thread;
	int			i;

	i = 0;
	while (i < nb_philo)
	{
		thread = create_thread(&all_philo[i]);
		if (!thread)
			return (8);
		all_thread[i] = thread;
		i ++;
	}
	return (0);
}
