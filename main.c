/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:58:00 by ocapers           #+#    #+#             */
/*   Updated: 2022/05/23 13:38:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_philos(t_info *info)
{
	int i = 0;
	pthread_t thread;

	gettimeofday(&info->create_time, NULL);
	while (i < info->number_of_philo)
	{
		info->philo[i].last_eat = info->create_time;
		pthread_create(&info->philo[i].thread, NULL, philo, &info->philo[i]);
		pthread_create(&thread, NULL, monitor, &info->philo[i]);
		pthread_detach(thread);
		i++;
	}
}

void free_philos(t_info *info)
{
	free(info->philo);
	int i = 0;
	while (i < info->number_of_philo)
	{
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	free(info->forks);
}

int main(int argc, char **argv)
{
	t_info info;
	
	if (argc < 5 || argc > 6)
		printf("error!\ninvalid number of arguments");	
	init(&info, argv);
	create_philos(&info);
	int i = 0;
	while (i < info.number_of_philo)
	{
		pthread_join(info.philo[i].thread, NULL);
		i++;
	}
	free_philos(&info);
}