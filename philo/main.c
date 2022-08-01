/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:44:11 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/01 15:02:43 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "parsing.h"

#include <unistd.h>
#include <stdio.h>

static int	main_end_cond(t_table *table)
{
	pthread_mutex_lock(&(table->end.mut));
	pthread_mutex_lock(&table->end_thread.mut);
	if (table->end_thread.end == table->phi_const.nb_philo
		|| table->end.end == 1 || table->phi_const.nb_repeat == 0)
	{
		table->end.end = 1;
		return (pthread_mutex_unlock(&(table->end_thread.mut)),
			pthread_mutex_unlock(&(table->end.mut)), 0);
	}
	return (pthread_mutex_unlock(&(table->end_thread.mut)),
		pthread_mutex_unlock(&(table->end.mut)), 1);
}

static void	check_last_meal(t_table *table, int *breaker, int i, int td)
{
	int	is_die;

	is_die = 0;
	pthread_mutex_lock(&(table->all_philo[i].last_meal_mut));
	if (timestamp(table->start) - table->all_philo[i].last_meal >= (long)td)
		is_die = 1;
	pthread_mutex_unlock(&(table->all_philo[i].last_meal_mut));
	if (is_die)
	{
		pthread_mutex_lock(&(table->end.mut));
		table->end.end = 1;
		pthread_mutex_unlock(&(table->end.mut));
		pthread_mutex_lock(&table->log);
		printf("%li %d %s\n", timestamp(table->start),
			table->all_philo[i].phi_number, "died");
		pthread_mutex_unlock(&table->log);
		*breaker = 1;
	}
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
		check_last_meal(table, &breaker, i, td);
		if (breaker)
			break ;
	}
	msleep_main(1, timestamp(0));
}

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
	while (timestamp(table.start) < START_LINE)
		usleep(300);
	table.start += START_LINE;
	while (main_end_cond(&table))
		check_death(&table, table.phi_const.time_to_die,
			table.phi_const.nb_philo);
	error = wait_all_thread(&table);
	if (error)
		return (free_table(&table), phi_display_error(error), 1);
	free_table(&table);
	return (0);
}
