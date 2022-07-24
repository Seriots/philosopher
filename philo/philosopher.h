/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:45:11 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/24 20:32:10 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>

typedef struct s_const
{
	int	nb_philo;
	int	nb_repeat;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}		t_const;

typedef struct s_end
{
	pthread_mutex_t	mut;
	int				end;
}	t_end;

typedef struct s_philo
{
	t_const			*phi_const;
	t_end			*end;
	pthread_mutex_t	*log;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int				phi_number;
	int				nb_of_meal;
	int				last_meal;
	long			start;
}					t_philo;

typedef struct s_table
{
	t_const			phi_const;
	t_end			end;
	pthread_mutex_t	log;
	pthread_mutex_t	*all_fork;
	t_philo			*all_philo;
}					t_table;

/*phi_error.c*/
void	phi_display_error(int key);

/*phi_init_philo.c*/
void	init_philo(t_table *table, t_philo *philo, long start, int i);

/*phi_init_table.c*/
int		init_table(t_table *table);

/*phi_free.c*/
void	free_forks(t_table *table);
void	free_table(t_table *table);
#endif
