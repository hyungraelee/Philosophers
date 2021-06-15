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

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 5 && argc != 6)
		return (ft_putendl_fd("Error : bad arguments.", 2));
	memset(&info, 0, sizeof(info));
	init_info(&info, argv);
	if (check_info(&info) < 0)
		return (-1);
}
