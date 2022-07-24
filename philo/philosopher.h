/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:45:11 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/24 17:08:15 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

typedef struct s_const
{
	int	nb_philo;
	int	nb_repeat;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}		t_const;

typedef struct s_table
{
	t_const	philo_const;
	
}		t_table;

/*phi_error.c*/
void	phi_display_error(int key);
#endif
