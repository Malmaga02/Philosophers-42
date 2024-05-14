#include "philo.h"

int	destroy_forks(t_room *room)
{
	int	i;
    int check;
	int	philos_nbr;

	philos_nbr = room->philos_nbr;
	i = 0;
    check = 0;
	while (philos_nbr > 0)
	{
		check = pthread_mutex_destroy(&room->forks[i]);
		if (check != 0)
            return (MUTEX_ERROR);
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
