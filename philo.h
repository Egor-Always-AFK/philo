/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:50:00 by ocapers           #+#    #+#             */
/*   Updated: 2022/06/13 18:19:44 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_philo
{
	int				number;
	int				is_eat;
	pthread_mutex_t	*left_hand;
	pthread_mutex_t	*right_hand;
	pthread_mutex_t	check_mutex;
	int				eat_count;
	pthread_t		thread;
	struct timeval	last_eat;
	struct timeval	create_time;
	struct s_info	*info;
}t_philo;

typedef struct s_info
{
	int								number_of_philo;
	unsigned long long				time_to_eat;
	unsigned long long				time_to_sleep;
	unsigned long long				time_to_die;
	int								number_of_eat;
	pthread_mutex_t					*forks;
	pthread_mutex_t					print_mutex;
	t_philo							*philo;
	int								im_dead;
	int								im_eat_many_times;
}t_info;

int						main(int argc, char **argv);

void					init(t_info *info, char **argv);

long					get_time(void);

void					error_message(char *error_message);

unsigned long long		time_to_ms(struct timeval time);

void					print_message(t_philo *philo, char *str);

void					*philo(void *argv);

void					pickup_fork(t_philo *philo);

void					sleeping(t_philo *philo);

void					thinking(t_philo *philo);

void					*monitor(void *arg);

void					ft_usleep(unsigned long long time);

unsigned long long		ft_current_time(void);

int						check(int ac, char **av);

int						ft_atoi_shell(const char *str);

int						ft_is_numeric_arg(const char *str);

int						ft_isdigit(int c);

int						check_rmd(const char *str);

void					init_part_two(t_info *info);

void					part_of_monitor( t_info *info, int i);

long					ft_atoi(const char *str);

unsigned long long		find_diff(struct timeval val1, struct timeval val2);

#endif 