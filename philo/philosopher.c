/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:44:11 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/26 20:45:38 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "parsing.h"

#include <stdio.h>

static int	main_end_cond(t_table *table)
{
	pthread_mutex_lock(&table->end_thread.mut);
	pthread_mutex_lock(&(table->end.mut));
	if (table->end_thread.end == table->phi_const.nb_philo
		|| table->end.end == 1)
		return (pthread_mutex_unlock(&(table->end_thread.mut)),
			pthread_mutex_unlock(&(table->end.mut)), 0);
	return (pthread_mutex_unlock(&(table->end_thread.mut)),
		pthread_mutex_unlock(&(table->end.mut)), 1);
}

static void	check_death(t_table *table, int td, int nb_philo)
{
	int		i;
	int		breaker;

	i = -1;
	pthread_mutex_lock(&(table->end.mut));
	breaker = table->end.end;
	pthread_mutex_unlock(&(table->end.mut));
	if (breaker)
		return ;
	while (++i < nb_philo)
	{
		pthread_mutex_lock(&(table->all_philo[i].last_meal_mut));
		if (timestamp(table->start) - table->all_philo[i].last_meal >= (long)td)
		{
			log_print(&(table->all_philo[i]),
				table->all_philo[i].phi_number, table->start, "died");
			breaker = 1;
		}
		pthread_mutex_unlock(&(table->all_philo[i].last_meal_mut));
		if (breaker)
			break ;
	}
	msleep(1);
}

static int	wait_all_thread(t_table *table)
{
	int	i;
	int	error;
	int	ret_val;

	i = 0;
	ret_val = 0;
	while (i < table->phi_const.nb_philo)
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
		return (phi_display_error(error), free_table(&table), 1);
	while (main_end_cond(&table))
		check_death(&table, table.phi_const.time_to_die,
			table.phi_const.nb_philo);
	error = wait_all_thread(&table);
	if (error)
		return (free_table(&table), phi_display_error(error), 1);
	free_table(&table);
	return (0);
}
