#include "philo_bonus.h"

int	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return (0);
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	if (fd == 2)
		return (-1);
	else
		return (1);
}
