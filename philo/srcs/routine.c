#include "philo.h"

void	pick_up_fork(t_philo *philo)
{

	pthread_mutex_lock(&(philo->info->fork[philo->fork_l]));
	print_msg(philo, FORK);
	pthread_mutex_lock(&(philo->info->fork[philo->fork_r]));
	print_msg(philo, FORK);

}

void	put_down_fork(t_philo *philo)
{

	pthread_mutex_unlock(&(philo->info->fork[philo->fork_l]));
	pthread_mutex_unlock(&(philo->info->fork[philo->fork_r]));

}

void	eat(t_philo *philo)
{
	pick_up_fork(philo);
	pthread_mutex_lock(&philo->eating);
	print_msg(philo, EATING);
	philo->realtime = get_time();
	while (get_time() - philo->realtime <= philo->info->time_to_eat \
	&& !philo->info->finish)
		usleep(1000);
	philo->meals++;
	pthread_mutex_unlock(&philo->eating);
	put_down_fork(philo);
}

void	sleeping(t_philo *philo)
{
	int	start;

	print_msg(philo, SLEEPING);
	start = get_time();
	while (get_time() - start <= philo->info->time_to_sleep \
	&& !philo->info->finish)
		usleep(1000);
}

void	thinking(t_philo *philo)
{
	print_msg(philo, THINKING);
}
