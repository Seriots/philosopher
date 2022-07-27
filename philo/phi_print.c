/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:01:23 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/27 20:40:28 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) != 0 && *(s2 + i) != 0 && *(s1 + i) == *(s2 + i))
		i++;
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}

void	log_print(t_philo *philo, int phi_num, long start, char *message)
{
	pthread_mutex_lock(philo->log);
	pthread_mutex_lock(&(philo->end->mut));
	if (!ft_strcmp(message, "is eating"))
	{
		pthread_mutex_lock(&(philo->last_meal_mut));
		philo->last_meal = timestamp(philo->start);
		pthread_mutex_unlock(&(philo->last_meal_mut));
	}
	if (!philo->end->end)
		printf("%li %d %s\n", timestamp(start), phi_num, message);
	pthread_mutex_unlock(philo->log);
	pthread_mutex_unlock(&(philo->end->mut));
}
