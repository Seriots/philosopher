/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:01:23 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/26 23:53:05 by lgiband          ###   ########.fr       */
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

char	*get_log(int phi_num, long time, char *message)
{
	return (0);
}

void	log_print(t_philo *philo, int phi_num, long start, char *message)
{
	char	*log;
	int		size;

	log = get_log(phi_num, timestamp(start), message);
	if (!log)
		return ;
	size = phi_strlen(log);
	pthread_mutex_lock(philo->log);
	pthread_mutex_lock(&(philo->end->mut));
	if (!philo->end->end)
		write(1, log, size);
	pthread_mutex_unlock(philo->log);
	free(log);
	if (!ft_strcmp(message, "died"))
		philo->end->end = 1;
	pthread_mutex_unlock(&(philo->end->mut));
}

void	log_print_main(t_table *table, int phi_num, long start, char *message)
{
	pthread_mutex_lock(&(table->log));
	printf("%li -%li- %d %s\n", timestamp(start), start, phi_num, message);
	pthread_mutex_unlock(&(table->log));
}
