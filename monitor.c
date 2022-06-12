/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:38:12 by ocapers           #+#    #+#             */
/*   Updated: 2022/06/12 16:38:12 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_info			*info;
	struct timeval	time;
	int				i;

	info = arg;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&info->philo->check_mutex);
		pthread_mutex_lock(&info->finish_mutex);
		gettimeofday(&time, NULL);
		part_of_monitor(info, i);
		if ((info->im_dead || (info->im_eat_many_times
					== info->number_of_philo)) || (info->number_of_eat != 0
				&& info->im_eat_many_times == info->number_of_philo))
			return (NULL);
		pthread_mutex_unlock(&info->finish_mutex);
		pthread_mutex_unlock(&info->philo->check_mutex);
		i++;
		if (i == info->number_of_philo)
			i = 0;
	}
	return (NULL);
}

void	part_of_monitor( t_info *info, int i)
{
	if (ft_current_time() - time_to_ms(info->philo[i].last_eat)
		> info->time_to_die && info->im_dead == 0)
	{
		pthread_mutex_lock(&info->print_mutex);
		printf("%ld %d %s\n",
			ft_current_time() - time_to_ms(info->philo[i].create_time),
			info->philo[i].number + 1, "died");
		info->im_dead = 1;
	}
}
