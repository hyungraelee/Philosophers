#include "philo.h"

void	print_status(t_philo *philo, int status)
{
	ft_putstr_fd("\tPhilosopher ", 1);
	ft_putnbr_fd(philo->nb, 1);
	if (status == FORK)
		ft_putendl_fd(" : has taken a fork", 1);
	else if (status == EATING)
		ft_putendl_fd(" : is eating", 1);
	else if (status == SLEEPING)
		ft_putendl_fd(" : is sleeping", 1);
	else if (status == THINKING)
		ft_putendl_fd(" : is thinking", 1);
	else if (status == DIED)
	{
		philo->info->finish = 1;
		ft_putendl_fd(" : is died", 1);
	}
}

void	print_msg(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->info->print);
	ft_putnbr_fd(get_time() - philo->info->basetime, 1);
	if (status == FULL)
	{
		philo->info->finish = 1;
		ft_putendl_fd("\tall philosophers take the meals", 1);
	}
	else
		print_status(philo, status);
	pthread_mutex_unlock(&philo->info->print);
}
