#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define RST "\033[0m"    /* Reset to default color */
# define RED "\033[1;31m" /* Bold Red */
# define G "\033[1;32m"   /* Bold Green */
# define Y "\033[1;33m"   /* Bold Yellow */
# define B "\033[1;34m"   /* Bold Blue */
# define M "\033[1;35m"   /* Bold Magenta */
# define C "\033[1;36m"   /* Bold Cyan */
# define W "\033[1;37m"   /* Bold White */

# define DEBUGGER 0

typedef pthread_mutex_t	t_mutx;

typedef struct s_data	t_data;

typedef struct s_fork
{
	t_mutx				fork;
	int					fork_id;
}						t_fork;

typedef struct s_philo
{
	int					id;
	long				meals_count;
	bool				full;
	long				last_meal_time;
	t_fork				*first_fork;
	t_fork				*second_fork;
	pthread_t			thread_id;
	t_mutx				pilo_mutex;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	long				philo_num;
	long				t_to_die;
	long				t_to_eat;
	long				t_to_sleep;
	long				num_meals_limit;
	long				start_routine;
	long				running_threads_num;
	bool				end_routine;
	bool				all_threads_ready;
	pthread_t			monitor;
	t_mutx				data_mutex;
	t_mutx				status_mutex;
	t_fork				*forks;
	t_philo				*philos;
}						t_data;

typedef enum s_philo_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}						t_philo_status;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}						t_opcode;

typedef enum e_time
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}						t_time;

/*
Safe Function
*/
void					mutex_handler(t_mutx *mutex, t_opcode opcode);
void					thread_handle(pthread_t *thread, void *(*foo)(void *),
							void *data, t_opcode opcode);

/*
Parsing
Error_handle
*/
void					parse_args(t_data *philo, char **av);
void					error_handle(char *msg);
void					free_string(char **str);
void					clean_exit(t_data *data);

/*
Utils
*/
int						ft_atoi(char *str);
size_t					ft_strlen(char *s);
long					get_time_day(t_time time);
void					ft_usleep(long usec, t_data *data);

/*
Philo Init
*/
void					init_data(t_data *data);

/*
routine
*/
void					routine_start(t_data *data);
void					*monitor_routine(void	*table);
void					thinking_routine(t_philo *philo, bool pre_routine);
void					de_sync(t_philo	*philo);

/*
sync
*/
void					wait_all_threads(t_data *data);
bool					all_threads_running(t_mutx	*mutex, long *threads, long philo_num);

/*
set & get
*/
void					set_bool(t_mutx *mutex, bool *dest, bool value);
bool					get_bool(t_mutx *mutex, bool *value);
void					set_long(t_mutx *mutex, long *dest, long value);
long					get_long(t_mutx *mutex, long *value);
bool					rotuine_finished(t_data *data);
void					increase_long(t_mutx *data_mutex, long	*threads_num);

/*
Routine message
*/
void					philo_status(t_philo_status status, t_philo *philo,
							bool bug_check);

#endif