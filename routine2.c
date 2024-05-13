#include "philo.h"

void    *philo_routine(void *var)
{
    t_philo *philo;
    int     action;

    action = -1;
    philo = (t_philo *)var;
	pthread_mutex_init(&philo->mutex_philo, NULL);
    pthread_mutex_lock(&(philo->room_ptr->forks[philo->l_fork]));
    took_fork(philo, action);
    pthread_mutex_lock(&(philo->room_ptr->forks[philo->r_fork]));
    took_fork(philo, action);
    eating(philo, action);
    pthread_mutex_unlock(&(philo->room_ptr->forks[philo->l_fork]));
    pthread_mutex_unlock(&(philo->room_ptr->forks[philo->r_fork]));
    sleeping(philo, action);
    thinking(philo, action);


}

void    *room_routine(void *var)
