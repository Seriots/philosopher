/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_parsing_setter_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:53:06 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/28 20:27:11 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

static int	str_to_int(char *arg)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (arg[i])
	{
		if (result > (result * 10) + (arg[i] - 48))
			return (-1);
		result = (result * 10) + (arg[i] - 48);
		i ++;
	}
	return (result);
}

int	set_phi_const(int argc, char **argv, t_const *phi_const)
{
	if (argc == 4)
		phi_const->nb_repeat = -1;
	else
	{
		phi_const->nb_repeat = str_to_int(argv[argc - 1]);
		if (phi_const->nb_repeat == -1)
			return (6);
	}
	phi_const->nb_philo = str_to_int(argv[0]);
	phi_const->time_to_die = str_to_int(argv[1]);
	phi_const->time_to_eat = str_to_int(argv[2]);
	phi_const->time_to_sleep = str_to_int(argv[3]);
	if (phi_const->nb_philo == -1 || phi_const->time_to_die == -1
		|| phi_const->time_to_eat == -1 || phi_const->time_to_sleep == -1)
		return (6);
	return (0);
}
