/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:11:17 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/28 21:22:13 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_BONUS_H
# define PHILOSOPHER_BONUS_H

# include <semaphore.h>
# include <pthread.h>

# define LOG_SEM "log"
# define FORKS_SEM "forks"
# define END_SEM "end"

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
	sem_t	*mut;
	int		value;
}			t_end;

typedef struct s_philo
{
	t_const			*phi_const;
	long			last_meal;
	int				phi_number;
	int				nb_of_meal;
	long			start;
	sem_t			*forks;
	sem_t			*log;
	t_end			*end;
}					t_philo;

typedef struct s_table
{
	t_const		phi_const;
	t_philo		*all_philo;
	pthread_t	*all_thread;
	long		start;
	sem_t		*forks;
	sem_t		*log;
	t_end		end;
}				t_table;

/*main.c*/
int	wait_all_thread(t_table *table);

/*phi_error.c*/
int		thread_creation_error(t_table *table, int error);
void	phi_display_error(int key);

/*phi_free.c*/
void	free_table(t_table *table);

/*phi_init_philo.c*/
void	init_philo(t_table *table, t_philo *philo, long start, int i);

/*phi_init_table.c*/
int		init_table(t_table *table, int nb_philo);

/*phi_create_thread.c*/
int		create_all_thread(pthread_t	*all_thread,
			t_philo *all_philo, int nb_philo);

/*phi_routine_loop_cond.c*/

/*phi_routine.c*/
void *routine(void *args);

/*phi_utils.c*/
void	msleep(long time, long start);
long	timestamp(long start);

/*phi_print.c*/
void	log_print(t_philo *philo, int phi_num, long start, char *message);
#endif
