/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:10:17 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/28 20:36:13 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
#include "parsing_bonus.h"

#include <stdio.h>

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

int	main(int argc, char **argv)
{
	t_table	table;
	int		error;

	error = parsing(argc, argv, &table.phi_const);
	if (error)
		return (phi_display_error(error), 1);
	error = init_table(&table, table.phi_const.nb_philo);
	if (error)
		return (phi_display_error(error), 1);
	error = create_all_thread(table.all_thread,
			table.all_philo, table.phi_const.nb_philo);
	if (error)
		return (thread_creation_error(&table, error));
	wait_all_thread(&table);
	printf("--main end--\n");
	return (0);
}
