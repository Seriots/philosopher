/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_print_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:03:20 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/26 23:30:39 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "philosopher.h"

void	phi_putnbr_long(long nbr)
{
	if (nbr >= 10)
		phi_putnbr_long(nbr / 10);
	phi_putchar((nbr % 10) + 48);
}

void	phi_putnbr_int(int nbr)
{
	if (nbr >= 10)
		phi_putnbr_long(nbr / 10);
	phi_putchar((nbr % 10) + 48);
		
}

void	phi_putchar(char c)
{
	write(1, &c, 1);
}

int	phi_strlen(char *s)
{
	int i;
	
	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	phi_putstr(char *s)
{
	write(1, s, phi_strlen(s));
}
