/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_print_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:01:23 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/30 17:39:11 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

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
	sem_wait(philo->log);
	sem_wait(philo->end->mut);
	if (!ft_strcmp(message, "is eating"))
	{
		sem_wait(philo->sem_last_meal);
		philo->last_meal = timestamp(philo->start);
		sem_post(philo->sem_last_meal);
	}
	if (!philo->end->value)
		printf("%li %d %s\n", timestamp(start), phi_num, message);
	sem_post(philo->log);
	sem_post(philo->end->mut);
}
