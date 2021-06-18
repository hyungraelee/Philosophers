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
	while (1)
	{
		if (get_time() - philo->realtime >= philo->info->time_to_die)
		{
			print_msg(philo, DIED);
			sem_post(philo->info->died);
			philo->info->finish = DIED;
			return (NULL);
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

int	routine(t_philo *philo)
{
	if (philo->nb % 2 == 0)
		usleep(1000 * philo->info->time_to_sleep);
	if (pthread_create(&philo->end, NULL, check_died, &philo->info))
		return (-1);
	pthread_detach(philo->end);
	if (pthread_create(&philo->thread, NULL, monitor, &philo))
		return (-1);
	pthread_detach(philo->thread);
	while (!philo->info->finish)
	{
		eat(philo);
		if (philo->info->must_eat_count > 0 && philo->meals == philo->info->must_eat_count)
		{
			sem_post(philo->info->full);
			philo->info->finish = FULL;
			break ;
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
	// free
	if (philo->info->finish == DIED)
		exit(1);
	else if (philo->info->finish == FULL)
		exit(0);
}

void	*check_full(void *args)
{
	t_info	*info;
	int		full_philo;

	info = args;
	full_philo = 0;
	while (1)
	{
		sem_wait(info->full);
		full_philo++;
		if (full_philo == info->num_of_philo)
			break ;
	}
	print_full(info);
	return (NULL);
}

int	init_process(t_info *info)
{
	int	i;
	pthread_t	full;

	i = -1;
	if (pthread_create(&full, NULL, check_full, &info))
		return (-1);
	pthread_detach(full);
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
	return (0);
}
