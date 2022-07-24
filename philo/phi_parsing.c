/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:01:04 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/24 18:14:00 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "parsing.h"

int	parsing(int argc, char **argv, t_const *phi_const)
{
	int	error;

	error = check_arguments(argc, argv);
	if (error)
		return (error);
	error = set_phi_const(argc - 1, &argv[1], phi_const);
	if (error)
		return (error);
	return (0);
}
