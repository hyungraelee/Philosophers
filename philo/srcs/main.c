#include "philo.h"

void	init_philo(t_philo *philo, char **argv)
{
	philo->num_of_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->must_eat_count = ft_atoi(argv[5]);
}

int		check_philo(t_philo *philo)
{
	if (philo->num_of_philo < 2 || philo->num_of_philo > 200)
		return (ft_putendl_fd("Error : Wrong number of philosopher", 2));
	else if (philo->time_to_die < 60)
		return (ft_putendl_fd("Error : Wrong number : time to die", 2));
	else if (philo->time_to_eat < 20)
		return (ft_putendl_fd("Error : Wrong number : time to eat", 2));
	else if (philo->time_to_sleep < 60)
		return (ft_putendl_fd("Error : Wrong number : time to sleep", 2));
	else if (philo->must_eat_count < 0)
		return (ft_putendl_fd("Error : Wrong number of meals", 2));
	else
		return (1);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc != 5 && argc != 6)
		return (ft_putendl_fd("Error : bad arguments.", 2));
	memset(&philo, 0, sizeof(philo));
	init_philo(&philo, argv);
	if (check_philo(&philo) < 0)
		return (-1);

	return (0);
}
