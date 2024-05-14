#include "philo.h"

int	check_philos(t_room *room)
{
	int	philos_nbr;
	int	i;

	i = 0;
	philos_nbr = room->philos_nbr;
	while (philos_nbr)
	{
		pthread_mutex_lock(&room->philo[i].mutex_philo);
		room->time = get_milliseconds() - room->philo[i].last_meal;
		pthread_mutex_unlock(&room->philo[i].mutex_philo);
		if (room->time >= room->time_to_die)
		{
			room->death = 1;
			death(&room->philo[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

void	room_routine(t_room *room)
{
	int	i;
	int	must_eat;

	i = 0;
	must_eat = room->must_eat;
	while (42)
	{
		if (!check_philos(room))
			break ;
		pthread_mutex_lock(&room->philo[i].mutex_philo);
		if (room->philo[i].eat_count == must_eat)
		{
			pthread_mutex_unlock(&room->philo[i].mutex_philo);
			break ;
		}
		pthread_mutex_unlock(&room->philo[i].mutex_philo);
	}
}