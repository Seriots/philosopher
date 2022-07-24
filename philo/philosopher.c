/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:44:11 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/24 18:13:34 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "parsing.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_table	table;
	int		error;

	error = parsing(argc, argv, &table.philo_const);
	if (error)
		return (phi_display_error(error), 1);
}
