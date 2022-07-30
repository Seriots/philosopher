/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:03:59 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/30 19:18:21 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "philosopher_bonus.h"

/*phi_parsing_setter.c*/
int	set_phi_const(int argc, char **argv, t_const *phi_const);

/*phi_parsing_checker.c*/
int	check_arguments(int argc, char **argv);

/*phi_parsing.c*/
int	parsing(int argc, char **argv, t_const *phi_const);

#endif