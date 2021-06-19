/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:10:04 by hyunlee           #+#    #+#             */
/*   Updated: 2021/06/19 18:29:44 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor(void *args)
{
	t_philo *philo;

	philo = args;
	while (1)
	{
		sem_wait(philo->eating);
		if (get_time() - philo->realtime >= philo->info->time_to_die)
		{
			philo->info->finish = DIED;
			philo->imdied = 1;
			sem_post(philo->info->died);
			sem_post(philo->eating);
			return (NULL);
		}
		sem_post(philo->eating);
		usleep(100);
	}
	return (NULL);
}

void	*check_died(void *args)
{
	t_philo	*philo;

	philo = args;
	sem_wait(philo->info->died);
	if (philo->imdied)
	{
		sem_post(philo->info->died);
		sem_post(philo->info->fork);
		sem_post(philo->info->fork);
		exit(1);
	}
	philo->info->finish = DIED;
	sem_post(philo->info->died);
	sem_post(philo->info->fork);
	sem_post(philo->info->fork);
	return (NULL);
}

int		routine(t_philo *philo)
{
	philo->realtime = get_time();
	if (thread_create_detach(&philo->end, check_died, philo) < 0)
		return (-1);
	if (thread_create_detach(&philo->thread, monitor, philo) < 0)
		return (-1);
	while (!philo->info->finish)
	{
		eat(philo);
		if (philo->info->must_eat_count > 0 && \
		philo->meals == philo->info->must_eat_count)
		{
			sem_post(philo->info->full);
			philo->info->finish = FULL;
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
	exit(0);
	return (1);
}
