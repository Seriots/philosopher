/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:44:11 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/25 22:13:47 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "parsing.h"

#include <stdio.h>

static int	main_end_cond(t_table *table)
{
	pthread_mutex_lock(&(table->end_thread.mut));
	if (table->end_thread.end == table->phi_const.nb_philo)
		return (pthread_mutex_unlock(&(table->end_thread.mut)), msleep(5), 0);
	return (pthread_mutex_unlock(&(table->end_thread.mut)), 1);
}

static void check_death(t_table *table, int td, int nb_philo)
{
	int		i;
	long	start;
	int		breaker;

	i = -1;
	start = table->all_philo[0].start;
	pthread_mutex_lock(&(table->end.mut));
	breaker = table->end.end;
	pthread_mutex_unlock(&(table->end.mut));
	if (breaker)
		return ;
	while (++i < nb_philo)
	{
		pthread_mutex_lock(&(table->all_philo[i].last_meal_mut));
		pthread_mutex_lock(&(table->all_philo[i].end_routine.mut));
		if (timestamp(start) - table->all_philo[i].last_meal >= (long)td && table->all_philo[i].end_routine.end == 0)
		{
			log_print(&(table->all_philo[i]),
				table->all_philo[i].phi_number, start, "died");
			breaker = 1;
		}
		pthread_mutex_unlock(&(table->all_philo[i].end_routine.mut));
		pthread_mutex_unlock(&(table->all_philo[i].last_meal_mut));
		if (breaker)
			break ;
	}
	msleep(1);
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
	error = create_all_thread(table.all_thread, table.all_philo, table.phi_const.nb_philo);
	if (error)
		return (phi_display_error(error), free_table(&table), 1);
	while (main_end_cond(&table))
		check_death(&table, table.phi_const.time_to_die, table.phi_const.nb_philo);
	log_print_main(&table, 0, 0, "main end");
	free_table(&table);
	return (0);
}
