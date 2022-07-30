/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_wait_thread_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:16:07 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/30 19:23:34 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

#include "philosopher_bonus.h"

int	wait_all_thread(t_table *table)
{
	int	i;
	int	error;
	int	ret_val;

	i = 0;
	ret_val = 0;
	while (i < table->phi_const.nb_philo && table->all_thread[i])
	{
		error = pthread_join(table->all_thread[i], 0);
		if (error && ret_val == 0)
			ret_val = error;
		i++;
	}
	return (ret_val);
}
