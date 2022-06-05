#include "philo.h"

void *monitor(void *arg)
{
	t_info *info;
	struct  timeval time;
	long long ms;

	info = arg;
	int i = 0;
	while (1)
	{
		pthread_mutex_lock(&info->philo->check_mutex);
		pthread_mutex_lock(&info->finish_mutex);
		gettimeofday(&time, NULL);
		//printf("\n\n%d\n\n", philo->info->im_eat_many_times);
		ms = time_to_ms(time) - time_to_ms(info->philo[i].last_eat);
		gettimeofday(&time, NULL);
		if (ms > info->time_to_die && info->im_dead == 0)
		{
			pthread_mutex_lock(&info->print_mutex);
			printf("%ld %d %s\n", time_to_ms(time) - time_to_ms(info->create_time), info->philo[i].number + 1, "died");
			pthread_mutex_unlock(&info->print_mutex);
			info->im_dead = 1;
		}
		if (info->im_dead || (info->im_eat_many_times == info->number_of_philo))
			break;
		pthread_mutex_unlock(&info->finish_mutex);
		pthread_mutex_unlock(&info->philo->check_mutex);
		i++;
		if (i == info->number_of_philo)
			i = 0;
	}
	return (NULL);
}