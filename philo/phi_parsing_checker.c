/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_parsing_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:22:36 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/01 14:52:53 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	check_nb_args(int argc)
{
	if (argc > 6)
		return (1);
	else if (argc < 5)
		return (2);
	return (0);
}

static int	check_is_number(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] > '9' || arg[i] < '0')
			return (0);
		i ++;
	}
	return (1);
}

static int	check_is_numbers(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!argv[i][0] || !check_is_number(argv[i]))
			return (3);
		i++;
	}
	return (0);
}

static int	check_nb_philo(char *arg)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (arg[i])
	{
		result = (result * 10) + (arg[i] - 48);
		i ++;
		if (result > 200)
			return (4);
	}
	if (result == 0)
		return (5);
	return (0);
}

int	check_arguments(int argc, char **argv)
{
	int	error;

	error = check_nb_args(argc);
	if (error)
		return (error);
	error = check_is_numbers(argc, argv);
	if (error)
		return (error);
	error = check_nb_philo(argv[1]);
	if (error)
		return (error);
	return (0);
}
