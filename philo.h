#ifndef PHILO_H
# define PHILO_H

# define PHILO_DEAD 0
# define PHILO_EAT 1
# define PHILO_SLEEP 2
# define PHILO_THINK 3
# define PHILO_TAKE_FORK 4

#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct s_philo
{
	int number;
	int is_eat;
	pthread_mutex_t *left_hand;
	pthread_mutex_t *right_hand;
	int eat_count;
	pthread_t thread;
	struct timeval last_eat;
	struct s_info *info;
}t_philo;

typedef struct s_info
{
	int number_of_philo;
	uint64_t time_to_eat;
	uint64_t time_to_sleep;
	uint64_t time_to_die;
	int number_of_eat;
	struct timeval create_time;
	pthread_mutex_t *forks;
	t_philo *philo;
	int im_dead;
	int im_eat_many_times;
}t_info;

int main(int argc, char **argv);

void init(t_info *info, char **argv);

uint64_t get_time(void);

void error_message(char *error_message);

long long	time_to_ms(struct timeval time);

void print_message(t_philo *philo, char *str);

void *philo(void *argv);

void pickup_fork(t_philo *philo);

void sleeping(t_philo *philo);

void thinking(t_philo *philo);

void *monitor(void *arg);

#endif 