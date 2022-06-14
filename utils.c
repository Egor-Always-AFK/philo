/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:12:55 by ocapers           #+#    #+#             */
/*   Updated: 2022/06/13 18:14:42 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	time_to_ms(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_message(t_philo *philo, char *str)
{
	struct timeval	time;

	pthread_mutex_lock(&philo->info->print_mutex);
	gettimeofday(&time, NULL);
	printf("%lld %d %s\n",
		ft_current_time() - time_to_ms(philo->create_time),
		philo->number + 1, str);
	pthread_mutex_unlock(&philo->info->print_mutex);
}

void	ft_usleep(unsigned long long time)
{
	unsigned long long	i;

	i = ft_current_time();
	while ((ft_current_time() - i) < time)
		usleep(100);
}

unsigned long long	ft_current_time(void)
{
	unsigned long long			value;
	struct timeval				time;

	gettimeofday(&time, NULL);
	value = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (value);
}

unsigned long long	find_diff(struct timeval val1, struct timeval val2)
{
	unsigned long long	conv_sec;
	unsigned long long	conv_usec;

	conv_sec = (val1.tv_sec - val2.tv_sec) * 1000;
	conv_usec = (val1.tv_usec - val2.tv_usec) / 1000;
	return (conv_sec + conv_usec);
}
