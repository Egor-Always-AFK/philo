/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:46:59 by ocapers           #+#    #+#             */
/*   Updated: 2022/06/12 19:53:56 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	print_message(philo, "is thinking");
}

void	sleeping(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_usleep(philo->info->time_to_sleep);
}

void	eating(t_philo *philo)
{

	pthread_mutex_lock(&philo->check_mutex);
	pthread_mutex_lock(&philo->info->finish_mutex);
	print_message(philo, "is eating");
	philo->eat_count += 1;
	if (philo->info->number_of_eat != 0
		&& (philo->eat_count == philo->info->number_of_eat))
		philo->info->im_eat_many_times += 1;
	pthread_mutex_unlock(&philo->info->finish_mutex);
	ft_usleep(philo->info->time_to_eat);
	gettimeofday(&philo->last_eat, NULL);
	pthread_mutex_unlock(philo->right_hand);
	pthread_mutex_unlock(philo->left_hand);
	pthread_mutex_unlock(&philo->check_mutex);
}

void	pickup_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_hand);
	print_message(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_hand);
	print_message(philo, "has taken a fork");
}

void	*philo(void *argv)
{
	t_philo	*philo;

	philo = argv;
	gettimeofday(&philo->create_time, NULL);
	if (philo->number % 2 == 0)
		usleep(100);
	while (1)
	{
		pickup_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
		pthread_mutex_lock(&philo->info->finish_mutex);
		if (philo->info->im_dead)
			break;
		pthread_mutex_unlock(&philo->info->finish_mutex);
	}
	return (NULL);
}
