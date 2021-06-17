#include "philo_bonus.h"

int		get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	*monitor(void *args)
{
	t_philo *philo;

	philo = args;
}

void	routine(t_philo *philo)
{
	pthread_t	th;

	if (pthread_create(&th, NULL, monitor, &philo))
		return (-1);
	while (!philo->info->finish)
	{

	}
}

int	init_process(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_of_philo)
	{
		info->philo[i].realtime = get_time();
		info->philo[i].pid = fork();
		if (info->philo[i].pid == 0)
			routine(&info->philo[i]);
		else if (info->philo[i].pid < 0)
			return (-1);
	}
	i = -1;
	while (++i < info->num_of_philo)
		wait(info->philo[i].pid);
	return (0);
}
