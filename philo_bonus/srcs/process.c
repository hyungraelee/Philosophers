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



int	routine(t_philo *philo)
{
	if (pthread_create(&philo->thread, NULL, monitor, &philo))
		return (-1);
	pthread_detach(philo->thread);
	while (!philo->info->finish)
	{
		eat(philo);
		// if (philo->info->must_eat_count > 0 && check_full(philo)
		if (philo->info->finish)
			break ;
		sleeping(philo);
		if (philo->info->finish)
			break ;
		thinking(philo);
		if (philo->info->finish)
			break ;
	}
	// free
	// exit
}

// void	*check_died(void *args)
// {
// 	t_info	*info;

// 	info = args;
// 	sem_wait(info->died);
// 	info->finish = DIED;
// 	return (NULL);
// }

// void	*check_full(void *args)
// {
// 	t_info	*info;

// 	info = args;
// }

int	init_process(t_info *info)
{
	int	i;
	pthread_t	end;
	pthread_t	full;

	i = -1;
	// if (pthread_create(&end, NULL, check_died, &info))
	// 	return (-1);
	// pthread_detach(end);
	// if (pthread_create(&full, NULL, check_full, &info))
	// 	return (-1);
	// pthread_detach(full);
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
		wait(info->philo[i].pid); // 모든 프로세스 다 끝내기 위해 이 방법으로 해볼것!
	// if (!info->finish)
	// 	usleep(500);
	return (0);
}
