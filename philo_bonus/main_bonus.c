/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:10:17 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/30 19:16:21 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
#include "parsing_bonus.h"

#include <stdio.h>

static int	check_all_nb_meal(t_table *table)
{
	int	i;

	i = 0;
	if (table->phi_const.nb_repeat == -1)
		return (0);
	while (i < table->phi_const.nb_philo)
	{
		sem_wait(table->sem_nb_meal);
		if (table->all_philo[i].nb_of_meal < table->phi_const.nb_repeat)
			return (sem_post(table->sem_nb_meal), 0);
		sem_post(table->sem_nb_meal);
		i++;
	}
	return (1);
}

static int	main_end_cond(t_table *table)
{
	sem_wait(table->end.mut);
	if (table->end.value == 1 || table->phi_const.nb_repeat == 0
		|| check_all_nb_meal(table))
	{
		table->end.value = 1;
		return (sem_post(table->end.mut), 0);
	}
	return (sem_post(table->end.mut), 1);
}

static void	check_last_meal(t_table *table, int *breaker, int i, int td)
{
	sem_wait(table->sem_last_meal);
	if (timestamp(table->start) - table->all_philo[i].last_meal >= (long)td)
	{
		sem_wait(table->end.mut);
		table->end.value = 1;
		sem_post(table->end.mut);
		sem_wait(table->log);
		printf("%li %d %s\n", timestamp(table->start),
			table->all_philo[i].phi_number, "died");
		sem_post(table->log);
		*breaker = 1;
	}
	sem_post(table->sem_last_meal);
}

static void	check_death(t_table *table, int td, int nb_philo)
{
	int		i;
	int		breaker;

	i = -1;
	sem_wait(table->end.mut);
	breaker = table->end.value;
	sem_post(table->end.mut);
	if (breaker)
		return ;
	while (++i < nb_philo)
	{
		check_last_meal(table, &breaker, i, td);
		if (breaker)
			break ;
	}
}

int	main(int argc, char **argv)
{
	t_table	table;
	int		error;

	unlink_sem();
	error = parsing(argc, argv, &table.phi_const);
	if (error)
		return (phi_display_error(error), 1);
	error = init_table(&table, table.phi_const.nb_philo);
	if (error)
		return (phi_display_error(error), unlink_sem(), 1);
	error = create_all_thread(table.all_thread,
			table.all_philo, table.phi_const.nb_philo);
	if (error)
		return (thread_creation_error(&table, error));
	while (main_end_cond(&table))
	{
		check_death(&table, table.phi_const.time_to_die,
			table.phi_const.nb_philo);
		msleep(1, timestamp(0));
	}
	wait_all_thread(&table);
	free_table(&table);
	return (0);
}
