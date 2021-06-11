#include "philo.h"

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	*routine(void *args)
{
	t_philo *philo;

	philo = args;

}

void	*monitor(void *args)
{
	t_philo *philo;

	philo = args;
}

int	init_thread(t_info *info)
{
	int			i;
	pthread_t	thread;

	i = -1;
	info->basetime = get_time();
	while (++i < info->num_of_philo)
	{
		info->philo[i].realtime = get_time();
		if (pthread_create(&thread, NULL, routine, &(info->philo[i])))
			return (-1);
		pthread_detach(thread);
		if (pthread_create(&(info->philo[i].thread), NULL, monitor, &(info->philo[i])))
			return (-1);
	}
	while (i-- > 0)
	{
		if (pthread_join(&(info->philo[i].thread), NULL))
			return (-1);
	}
	return (0);
}
