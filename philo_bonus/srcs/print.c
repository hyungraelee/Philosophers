#include "philo_bonus.h"

void	print_status(t_philo *philo, int status)
{
	ft_putstr_fd("\tPhilosopher ", 1);
	ft_putnbr_fd(philo->nb + 1, 1);
	if (status == FORK)
		ft_putendl_fd(" : has taken a fork", 1);
	else if (status == EATING)
		ft_putendl_fd(" : is eating", 1);
	else if (status == SLEEPING)
		ft_putendl_fd(" : is sleeping", 1);
	else if (status == THINKING)
		ft_putendl_fd(" : is thinking", 1);
}

void	print_msg(t_philo *philo, int status)
{
	sem_wait(philo->info->print);
	if (philo->info->finish)
	{
		sem_post(philo->info->print);
		return ;
	}
	ft_putnbr_fd(get_time() - philo->info->basetime, 1);
	print_status(philo, status);
	sem_post(philo->info->print);
}

void	print_full(t_info *info)
{
	sem_wait(info->print);
	ft_putnbr_fd(get_time() - info->basetime, 1);
	ft_putendl_fd("\tall philosophers take the meals", 1);
	sem_post(info->print);
}

void	print_died(t_philo *philo)
{
	sem_wait(philo->info->print);
	ft_putnbr_fd(get_time() - philo->info->basetime, 1);
	ft_putstr_fd("\tPhilosopher ", 1);
	ft_putnbr_fd(philo->nb + 1, 1);
	ft_putendl_fd(" : is died", 1);
	sem_post(philo->info->print);
}
