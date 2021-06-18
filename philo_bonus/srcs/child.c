#include "philo_bonus.h"

void	*monitor(void *args)
{
	t_philo *philo;

	philo = args;
	while (1)
	{
		if (get_time() - philo->realtime >= philo->info->time_to_die)
		{
			sem_post(philo->info->died);
			philo->info->finish = DIED;
			exit(1);
		}
		usleep(100);
	}
	return (NULL);
}

void	*check_died(void *args)
{
	t_info	*info;

	info = args;
	sem_wait(info->died);
	info->finish = DIED;
	sem_post(info->died);
	return (NULL);
}

int		routine(t_philo *philo)
{
	philo->realtime = get_time();
	if (thread_create_detach(&philo->end, check_died, philo->info) < 0)
		return (-1);
	if (thread_create_detach(&philo->thread, monitor, philo) < 0)
		return (-1);
	while (!philo->info->finish)
	{
		eat(philo);
		if (philo->info->must_eat_count > 0 && \
		philo->meals == philo->info->must_eat_count)
		{
			sem_post(philo->info->full);
			philo->info->finish = FULL;
		}
		if (philo->info->finish)
			break ;
		sleeping(philo);
		if (philo->info->finish)
			break ;
		thinking(philo);
		if (philo->info->finish)
			break ;
	}
	exit(0);
	return (1);
}
