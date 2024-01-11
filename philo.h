#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>

typedef pthread_mutex_t	t_mutx;

typedef struct s_data t_data;

typedef struct s_fork
{
	t_mutx				fork;
	int					fork_id;
}						t_fork;

typedef struct s_philo
{
	int					id;
	size_t				meals_count;
	bool				full;
	size_t				last_meal_time;
	t_fork				*right_fork;
	t_fork				*left;
	pthread_t			thread_id;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	size_t				philo_num;
	size_t				t_to_die;
	size_t				t_to_eat;
	size_t				t_to_sleep;
	size_t				num_meals_limit;
	size_t				start_experiment;
	bool				end_experiment;
	t_fork				*forks;
	t_philo				*philos;
}						t_data;

/*
Parsing
*/
void					parse_args(char **av);
void					init_philo(t_data *philo, char **av);

/*
Error_handle
*/
void					error_handle(char **av, char *msg);
void					free_string(char **str);

/*
Utils
*/
int	ft_atoi(char *str);
size_t	ft_strlen(char *s);

#endif