/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:07:21 by hyunlee           #+#    #+#             */
/*   Updated: 2021/06/19 18:07:22 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	else if (status == DIED)
		ft_putendl_fd(" : is died", 1);
}

void	print_msg(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->info->print);
	if (philo->info->finish)
	{
		pthread_mutex_unlock(&philo->info->print);
		return ;
	}
	ft_putnbr_fd(get_time() - philo->info->basetime, 1);
	if (status == FULL)
		ft_putendl_fd("\tall philosophers take the meals", 1);
	else
		print_status(philo, status);
	pthread_mutex_unlock(&philo->info->print);
}
