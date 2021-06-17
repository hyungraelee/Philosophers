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
		info->philo[i].info = info;
	}
	info->end = sem_open(SEM_END, O_CREAT, 0644, 0);
	info->full = sem_open(SEM_FULL, O_CREAT, 0644, 0);
	info->fork = sem_open(SEM_FORK, O_CREAT, 0644, info->num_of_philo);
	info->print = sem_open(SEM_PRINT, O_CREAT, 0644, 1);
	return (1);
}


int	main(int argc, char **argv)
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
	if (init_process(&info) < 0)
		return (1);

	return (0);
}
