#include "philo.h"

void	took_fork(t_philo *philo, int action)
{
	pthread_mutex_lock(&philo->room_ptr->print);
	print_action(TOOK_FORK, philo);
	pthread_mutex_unlock(&philo->room_ptr->print);
}

void	eating(t_philo *philo, int action)
{
	pthread_mutex_lock(&philo->room_ptr->print);
	print_action(EATING, philo);
	pthread_mutex_unlock(&philo->room_ptr->print);
	usleep(philo->room_ptr->time_to_eat);
	pthread_mutex_lock(&philo->mutex_philo);
	philo->last_meal = get_ms();
	
	pthread_mutex_unlock(&philo->mutex_philo);
	
}


void	sleeping(t_philo *philo, int action)
{
	pthread_mutex_lock(&philo->room_ptr->print);
	print_action(SLEEPING, philo);
	pthread_mutex_unlock(&philo->room_ptr->print);
	usleep(philo->room_ptr->time_to_sleep);
}

void	thinking(t_philo *philo, int action)
{
	pthread_mutex_lock(&philo->room_ptr->print);
	print_action(THINKING, philo);
	pthread_mutex_unlock(&philo->room_ptr->print);	
}

void	get_time(t_philo *philo)
{

}