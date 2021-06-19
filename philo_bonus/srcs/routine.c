/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:10:14 by hyunlee           #+#    #+#             */
/*   Updated: 2021/06/19 18:10:15 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat(t_philo *philo)
{
	sem_wait(philo->info->fork);
	print_msg(philo, FORK);
	sem_wait(philo->info->fork);
	print_msg(philo, FORK);
	sem_wait(philo->eating);
	print_msg(philo, EATING);
	philo->realtime = get_time();
	while (get_time() - philo->realtime <= philo->info->time_to_eat \
	&& !philo->info->finish)
		usleep(1000);
	philo->meals++;
	sem_post(philo->eating);
	sem_post(philo->info->fork);
	sem_post(philo->info->fork);
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
