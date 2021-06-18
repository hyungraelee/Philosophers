#include "philo_bonus.h"

int		get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int		thread_create_detach(pthread_t *thread, void *func, void *arg)
{
	if (pthread_create(thread, NULL, func, arg))
		return (-1);
	pthread_detach(*thread);
	return (1);
}

sem_t	*ft_sem_open(char *name, int num)
{
	sem_unlink(name);
	return (sem_open(name, O_CREAT | O_EXCL, 0644, num));
}