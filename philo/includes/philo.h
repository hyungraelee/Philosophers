#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include "utils.h"

# define FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5
# define FULL 6


typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

struct s_info
{
	int		num_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat_count;
	int		basetime;
	int		finish;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	t_philo	*philo;
};

struct s_philo
{
	int				nb;
	int				fork_l;
	int				fork_r;
	int				realtime;
	int				meals;
	pthread_t		thread;
	pthread_mutex_t	eating;
	t_info			*info;
};


int		init_thread(t_info *info);
int		get_time(void);
void	print_msg(t_philo *philo, int status);
void	eat(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

#endif
