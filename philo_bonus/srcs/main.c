#include "philo_bonus.h"

void	init_info(t_info *info, char **argv)
{
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->must_eat_count = 0;
	if (argv[5])
		info->must_eat_count = ft_atoi(argv[5]);
	info->basetime = 0;
	info->finish = 0;
	info->print_died = 0;
	info->died = ft_sem_open(SEM_END, 0);
	info->full = ft_sem_open(SEM_FULL, 0);
	info->fork = ft_sem_open(SEM_FORK, info->num_of_philo);
	info->print = ft_sem_open(SEM_PRINT, 1);
}

int		check_info(t_info *info)
{
	if (info->num_of_philo < 0 || info->num_of_philo > 200)
		return (ft_putendl_fd("Error : Wrong number of philosopher", 2));
	else if (info->time_to_die < 60)
		return (ft_putendl_fd("Error : Wrong number : time to die", 2));
	else if (info->time_to_eat < 60)
		return (ft_putendl_fd("Error : Wrong number : time to eat", 2));
	else if (info->time_to_sleep < 60)
		return (ft_putendl_fd("Error : Wrong number : time to sleep", 2));
	else if (info->must_eat_count < 0)
		return (ft_putendl_fd("Error : Wrong number of meals", 2));
	else
		return (1);
}

int		init_philo(t_info *info)
{
	int	i;

	i = -1;
	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (!info->philo)
		return (-1);
	while (++i < info->num_of_philo)
	{
		info->philo[i].nb = i;
		info->philo[i].realtime = 0;
		info->philo[i].meals = 0;
		info->philo[i].imdied = 0;
		info->philo[i].info = info;
		make_sem_name(&info->philo[i]);
		info->philo[i].eating = ft_sem_open(info->philo[i].eating_sem_name, 1);
	}
	return (1);
}

void	clean_info(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_of_philo)
	{
		sem_close(info->philo[i].eating);
		sem_unlink(info->philo[i].eating_sem_name);
		free(info->philo[i].eating_sem_name);
	}
	if (info->finish == DIED)
		sem_post(info->full);
	sem_close(info->died);
	sem_close(info->full);
	sem_close(info->fork);
	sem_close(info->print);
	sem_unlink(SEM_END);
	sem_unlink(SEM_FULL);
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_PRINT);
	free(info->philo);
}

int		main(int argc, char **argv)
{
	t_info	info;

	if (argc != 5 && argc != 6)
		return (ft_putendl_fd("Error : bad arguments.", 2));
	memset(&info, 0, sizeof(info));
	init_info(&info, argv);
	if (check_info(&info) < 0)
		return (1);
	if (init_philo(&info) < 0)
		return (1);
	if (process(&info) < 0)
		return (1);
	clean_info(&info);
	return (0);
}
