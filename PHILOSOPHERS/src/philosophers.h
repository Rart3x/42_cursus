/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:14:17 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/11 11:06:49 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdio.h>
# include <threads.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <sys/time.h>
# define DEATH "died 💀"
# define EAT "is eating 🍕"
# define FORK "has taken a fork 🍴"
# define SLEEP "is sleeping 💤"
# define THINK "is thinking 💭"

typedef struct s_data
{
	int				death_time;
	int				eat_time;
	int				end;
	int				must_eat;
	int				nb_philo;
	int				nb_forks;
	int				sleep_time;
	long			start_time;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	m_end;
	pthread_mutex_t	m_meal;
	pthread_mutex_t	m_print;

}t_data;

typedef struct s_philo
{
	t_data			*data;
	int				eat_count;
	int				is_eating;
	int				is_dead;
	long			last_meal;
	int				n_philo;
	pthread_t		thread;
	pthread_mutex_t	*m_fork_l;
	pthread_mutex_t	*m_fork_r;
	pthread_mutex_t	*m_eat_c;
	pthread_mutex_t	*m_last_m;

}t_philo;

/*-----------Utils_f----------*/
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		are_digit(int argc, char **argv);
/*-----------Philosophers_f----------*/
int			is_dead(t_philo *philo);
void		*check_death(void *philo);
int			print_routine(t_philo *philo, char *str);
void		*routine(void *philo);
/*-----------Action_f----------*/
int			eat(t_philo *philo);
int			take_fork(t_philo *philo);
/*-----------Init_f----------*/
void		init_philo(t_philo *philo, t_data *data);
void		init_data(int argc, char **argv, t_data *data, t_philo *philo);
void		open_thread(t_philo *philo);
/*-----------Free_Destroy_f----------*/
void		free_array2d(void **arr);
void		destroy_free(t_philo *philo);
/*-----------Time_f----------*/
long		timestamp(void);
void		ft_usleep(t_philo *philo, int ms_time);
/*-----------Errors_f----------*/
void		error_args(void);
void		error_digit(void);
void		error_overflow(void);

#endif
