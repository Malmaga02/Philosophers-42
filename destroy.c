#include "philo.h"

int	destroy_forks(t_room *room)
{
	int	i;
	int	philos_nbr;

	philos_nbr = room->philos_nbr;
	i = 0;
	while (philos_nbr > 0)
	{
		pthread_mutex_destroy(&room->forks[i]);
		i++;
		philos_nbr--;
	}
	return (1);
}

void	free_all(t_room *room)
{
	pthread_mutex_destroy(&room->print);
	pthread_mutex_destroy(&room->mutex_room);
	destroy_forks(room);
	free(room->forks);
	free(room->philo);
}
