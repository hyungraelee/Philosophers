#include "philo.h"

void	pick_up_fork(t_philo *philo)
{
	if (philo->nb % 2 == 0)	//Â¦¼ö¹ø
	{
		pthread_mutex_lock(&(philo->info->fork[philo->fork_l]));
		pthread_mutex_lock(&(philo->info->fork[philo->fork_r]));
	}
	else	//È¦¼ö¹ø
	{
		pthread_mutex_lock(&(philo->info->fork[philo->fork_r]));
		pthread_mutex_lock(&(philo->info->fork[philo->fork_l]));
	}
}

void	put_down_fork(t_philo *philo)
{
	if (philo->nb % 2 == 0)	//Â¦¼ö¹ø
	{
		pthread_mutex_unlock(&(philo->info->fork[philo->fork_l]));
		pthread_mutex_unlock(&(philo->info->fork[philo->fork_r]));
	}
	else	//È¦¼ö¹ø
	{
		pthread_mutex_unlock(&(philo->info->fork[philo->fork_r]));
		pthread_mutex_unlock(&(philo->info->fork[philo->fork_l]));
	}
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
	print_msg(philo, SLEEPING);
	usleep(1000 * philo->info->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_msg(philo, THINKING);
}
