#include "philo_bonus.h"

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

void	died_process(t_philo *philo)
{
	print_died(philo);
	philo->info->print_died++;
}

int		process(t_info *info)
{
	int			i;
	pthread_t	full;
	int			status;

	i = -1;
	if (thread_create_detach(&full, check_full, info) < 0)
		return (-1);
	info->basetime = get_time();
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
	{
		waitpid(info->philo[i].pid, &status, 0);
		if (WEXITSTATUS(status) == 1 && info->print_died == 0)
			died_process(&info->philo[i]);
	}
	return (0);
}
