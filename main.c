/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:58:00 by ocapers           #+#    #+#             */
/*   Updated: 2022/06/05 19:16:22 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_philos(t_info *info, pthread_t thread)
{
	int i = -1;


	while (++i < info->number_of_philo)
	{
		pthread_create(&info->philo[i].thread, NULL, philo, &info->philo[i]);
		pthread_detach(info->philo[i].thread);
	}
	monitor(info);
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
	pthread_t thread;
	
	if (argc < 5 || argc > 6)
		printf("error!\ninvalid number of arguments");	
	init(&info, argv);
	create_philos(&info, thread);
	free_philos(&info);
}