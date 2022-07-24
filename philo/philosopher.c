/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:44:11 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/24 20:34:32 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "parsing.h"

#include <stdio.h>

void	display_all_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->phi_const->nb_philo)
	{
		printf("number: %d\n", philo[i].phi_number);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_table	table;
	int		error;

	error = parsing(argc, argv, &table.phi_const);
	if (error)
		return (phi_display_error(error), 1);
	error = init_table(&table);
	if (error)
		return (phi_display_error(error), 1);
	display_all_philo(table.all_philo);
	free_table(&table);
	return (0);
}
