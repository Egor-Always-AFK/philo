/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:12:55 by ocapers           #+#    #+#             */
/*   Updated: 2022/05/23 11:52:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_to_ms(struct timeval time)
{
	long long		ms;

	ms = time.tv_sec * 1000;
	ms += time.tv_usec / 1000;
	return (ms);
}

void print_message(t_philo *philo, char *str)
{
	long long		ms;
	struct timeval	time;

	if (!philo->info->im_dead)
	{
		gettimeofday(&time, NULL);
		ms = time_to_ms(time) - time_to_ms(philo->info->create_time);
		printf("%lld %d %s\n", ms, philo->number + 1, str);
	}
}

void my_usleep(int time)
{
	int i;

	i = 1;
	while (i <= (time))
	{
		usleep(200);
		i += 200;
	}
}