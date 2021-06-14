#include "philo.h"

void	pick_up_fork(t_philo *philo)
{
	if (philo->nb != philo->info->num_of_philo)
	{
		pthread_mutex_lock(&(philo->info->fork[philo->fork_l]));
		// if (philo->info->finish)
		// {
		// 	pthread_mutex_unlock(&(philo->info->fork[philo->fork_l]));
		// 	return (0);
		// }
		pthread_mutex_lock(&(philo->info->fork[philo->fork_r]));
	}
	else
	{
		pthread_mutex_lock(&(philo->info->fork[philo->fork_r]));
		// if (philo->info->finish)
		// {
		// 	pthread_mutex_unlock(&(philo->info->fork[philo->fork_r]));
		// 	return (0);
		// }
		pthread_mutex_lock(&(philo->info->fork[philo->fork_l]));
	}
	// return (1);
}

void	put_down_fork(t_philo *philo)
{
	if (philo->nb != philo->info->num_of_philo)
	{
		pthread_mutex_unlock(&(philo->info->fork[philo->fork_l]));
		// if (philo->info->finish)
		// 	return (0);
		pthread_mutex_unlock(&(philo->info->fork[philo->fork_r]));
	}
	else
	{
		pthread_mutex_unlock(&(philo->info->fork[philo->fork_r]));
		// if (philo->info->finish)
		// 	return (0);
		pthread_mutex_unlock(&(philo->info->fork[philo->fork_l]));
	}
	// return (1);
}

void	eat(t_philo *philo)
{
	pick_up_fork(philo);
	print_msg(philo, EATING);
	philo->realtime = get_time();
	pthread_mutex_lock(&philo->eating);
	usleep(1000 * philo->info->time_to_eat);
	philo->meals++;
	pthread_mutex_unlock(&philo->eating);
	put_down_fork(philo);
}

void	sleeping(t_philo *philo)
{
	int	start;

	print_msg(philo, SLEEPING);
	start = get_time();
	while (get_time() - start <= philo->info->time_to_sleep && !philo->info->finish)
		usleep(1000);
}

void	thinking(t_philo *philo)
{
	print_msg(philo, THINKING);
}
