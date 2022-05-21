/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:40:20 by ocapers           #+#    #+#             */
/*   Updated: 2022/05/21 10:36:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init(t_info *info, char **argv)
{
	info->number_of_philo = atoi(argv[1]);
	info->time_to_die = atoi(argv[2]);
	info->time_to_eat = atoi(argv[3]);
	info->time_to_sleep = atoi(argv[4]);
	if (argv[5] != NULL)
		info->number_of_eat = atoi(argv[5]);
	info->im_dead = 0;
	info->im_eat_many_times = 0;
	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->number_of_philo);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->number_of_philo);
	int i = 0;
	while (i < info->number_of_philo)
	{
		pthread_mutex_init(&info->forks[i], NULL);
		info->philo[i].number = i;
		info->philo[i].is_eat = 0;
		info->philo[i].eat_count = 0;
		info->philo[i].right_hand = &info->forks[i];
		if (i == 0)
			info->philo[i].left_hand = &info->forks[info->number_of_philo - 1];
		else
			info->philo[i].left_hand = &info->forks[i - 1];
		info->philo[i].info = info;
		i++;
	}
}