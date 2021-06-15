#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include "utils.h"

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
	t_philo	*philo;
};

struct	s_philo
{
	int		nb;
};



#endif
