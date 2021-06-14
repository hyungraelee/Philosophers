#include "philo.h"

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int		check_meals(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->info->num_of_philo)
	{
		if (philo->info->philo[i].meals != philo->info->must_eat_count)
			return (0);
	}
	ft_putstr_fd(B_GREEN, 1);
	print_msg(philo, FULL);
	ft_putstr_fd(C_RESET, 1);
	philo->info->finish = FULL;
	return (1);
}

void	*routine(void *args)
{
	t_philo *philo;

	philo = args;
	while (!philo->info->finish)
	{
		if (philo->info->finish)
			break ;
		eat(philo);
		if (philo->info->must_eat_count > 0 && check_meals(philo))
			break ;
		if (philo->info->finish)
			break ;
		sleeping(philo);
		if (philo->info->finish)
			break ;
		thinking(philo);
		if (philo->info->finish)
			break ;
		usleep(500);
	}
	return (NULL);
}

void	*monitor(void *args)
{
	t_philo *philo;

	philo = args;
	while (!philo->info->finish)
	{
		pthread_mutex_lock(&philo->eating);
		if (get_time() - philo->realtime >= philo->info->time_to_die)
		{
			ft_putstr_fd(B_RED, 1);
			print_msg(philo, DIED);
			ft_putstr_fd(C_RESET, 1);
			philo->info->finish = DIED;
			pthread_mutex_unlock(&philo->eating);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->eating);
		usleep(500);
	}
	return (NULL);
}

int	init_thread(t_info *info)
{
	int			i;
	pthread_t	thread;

	i = -1;
	info->basetime = get_time();
	// thread = (pthread_t *)malloc(sizeof(pthread_t) * info->num_of_philo);
	while (++i < info->num_of_philo)
	{
		info->philo[i].realtime = get_time();
		if (pthread_create(&thread, NULL, routine, &(info->philo[i])))
			return (-1);
		pthread_detach(thread);
		// if (pthread_create(&thread[i], NULL, routine, &(info->philo[i])))
		// 	return (-1);
		if (pthread_create(&(info->philo[i].thread), NULL, monitor, &(info->philo[i])))
			return (-1);
		usleep(500);
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		// if (pthread_join(thread[i], NULL))
		// 	return (-1);
		if (pthread_join(info->philo[i].thread, NULL))
			return (-1);
	}
	return (0);
}
