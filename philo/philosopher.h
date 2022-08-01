/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:45:11 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/01 15:01:18 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>

# define START_LINE 30

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
	t_end			*end_thread;
	pthread_mutex_t	*log;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int				take_l_fork;
	int				take_r_fork;
	pthread_mutex_t	last_meal_mut;
	long			last_meal;
	int				phi_number;
	int				quota;
	int				nb_of_meal;
	pthread_mutex_t	*setup;
	long			start;
}					t_philo;

typedef struct s_table
{
	t_const			phi_const;
	t_end			end;
	t_end			end_thread;
	pthread_mutex_t	log;
	pthread_mutex_t	setup;
	pthread_mutex_t	*all_fork;
	t_philo			*all_philo;
	pthread_t		*all_thread;
	long			start;
}					t_table;

/*main.c*/
int		wait_all_thread(t_table *table);

/*phi_error.c*/
int		thread_creation_error(t_table *table, int error);
void	phi_display_error(int key);

/*phi_init_philo.c*/
void	init_philo(t_table *table, t_philo *philo, long start, int i);

/*phi_init_table.c*/
int		init_table(t_table *table, int nb_philo);

/*phi_free.c*/
void	free_forks(t_table *table);
void	free_table(t_table *table);

/*phi_create_thread.c*/
int		create_all_thread(pthread_t	*all_thread,
			t_philo *all_philo, int nb_philo);

/*phi_routine.c*/
void	*routine_solo(void *args);
void	*routine(void *args);

/*phi_routine_loop_cond.c*/
int		run_loop(t_philo *philo);

/*phi_routine_action.c*/
void	phi_sleep(t_philo *philo);
void	phi_eat(t_philo *philo);
void	grab_right_fork(t_philo *philo);
void	grab_left_fork(t_philo *philo);

/*phi_utils.c*/
void	msleep(long time, long start, t_philo *philo);
void	msleep_main(long time, long start);
long	timestamp(long start);

/*phi_print.c*/
void	log_print(t_philo *philo, int phi_num, long start, char *message);
#endif
