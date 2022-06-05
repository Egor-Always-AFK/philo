/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:12:55 by ocapers           #+#    #+#             */
/*   Updated: 2022/06/05 19:25:09 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_to_ms(struct timeval time)
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
		// pthread_mutex_lock(&philo->info->print_mutex);
		printf("%ld %d %s\n", time_to_ms(time) - time_to_ms(philo->info->create_time), philo->number + 1, str);
		// pthread_mutex_unlock(&philo->info->print_mutex);
	}
}

void	ft_usleep(long int time)
{
	long	i;

	i = ft_current_time();
	while ((ft_current_time() - i) < time)
		usleep(100);
}

long	ft_current_time(void)
{
	long		value;
	struct timeval	time;

	gettimeofday(&time, NULL);
	value = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (value);
}