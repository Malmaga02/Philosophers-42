/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:45:22 by chsassi           #+#    #+#             */
/*   Updated: 2024/05/01 18:45:23 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum	e_action
{
	TOOK_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_action;

typedef enum	e_error
{
	INVALID_PARSING,
	INVALID_ARGS,
	PHILO_ALLOC,
	THREAD_ERROR,
	ROOM_INIT
}	t_error;


typedef struct	s_philo
{
	pthread_t		id;
	pthread_mutex_t	mutex_philo;
	int				philo_index;
	long			start_time;
	int				last_meal;
	int				l_fork;
	int				r_fork;
	t_room			*room_ptr;
	int				action;
	long			time_action;
}	t_philo;

typedef struct	s_room
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	mutex_room;
	int				philos_nbr;
	int				eat_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long			start_time;
	long			time;
}	t_room;

/* Init */

void	init_room(t_room *pRoom, int ac, char **av);
void	init_philos(t_room *pRoom);

/* Routine */
void	*philo_routine(void *var);

/* Utils */

int		ft_atoi(char *s);
int		get_ms(void);
int		parse_args(int ac, char **av);
int		print_action(t_action action_type, t_philo *philo);
int		print_error(t_error error_type);

#endif