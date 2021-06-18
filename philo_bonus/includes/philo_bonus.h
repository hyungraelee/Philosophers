#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <semaphore.h>
# include "utils.h"

# define FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5
# define FULL 6
# define SEM_END "sem_end"
# define SEM_FULL "sem_full"
# define SEM_FORK "sem_fork"
# define SEM_PRINT "sem_print"

typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

struct	s_info
{
	int		num_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat_count;
	int		basetime;
	int		finish;
	sem_t	*died;
	sem_t	*full;
	sem_t	*fork;
	sem_t	*print;
	t_philo	*philo;
};

struct	s_philo
{
	int			nb;
	int			realtime;
	int			meals;
	pid_t		pid;
	pthread_t	thread;
	pthread_t	end;
	// pthread_t	full;
	t_info		*info;
};



#endif
