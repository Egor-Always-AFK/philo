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
	int				i;

	info = arg;
	i = 0;
	while (1)
	{
		part_of_monitor(info, i);
		if ((info->im_dead || (info->im_eat_many_times
					== info->number_of_philo)) || (info->number_of_eat != 0
				&& info->im_eat_many_times == info->number_of_philo))
			return (NULL);
		i++;
		if (i == info->number_of_philo)
			i = 0;
	}
	return (NULL);
}

void	part_of_monitor(t_info *info, int i)
{
	unsigned long long	time_since_meal;
	struct timeval		now;

	pthread_mutex_lock(&info->philo[i].check_mutex);
	gettimeofday(&now, NULL);
	time_since_meal = find_diff(now, info->philo[i].last_eat);
	pthread_mutex_unlock(&info->philo[i].check_mutex);
	if (time_since_meal > info->time_to_die && info->im_dead == 0)
	{
		pthread_mutex_lock(&info->print_mutex);
		printf("%lld %d %s\n",
			ft_current_time() - time_to_ms(info->philo[i].create_time),
			info->philo[i].number + 1, "died");
		info->im_dead = 1;
	}
}
