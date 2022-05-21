# include "philo.h"

void thinking(t_philo *philo)
{
	print_message(philo, "is thinking");
}

void sleeping(t_philo *philo)
{
	print_message(philo, "is sleeping");
	usleep(philo->info->time_to_sleep);
}

void eating(t_philo *philo)
{
	long long ms;

	gettimeofday(&philo->last_eat, NULL);
	ms = time_to_ms(philo->last_eat) - time_to_ms(philo->info->create_time);
	if (!philo->info->im_dead)
		printf("%lld\t%d\t %s\n", ms, philo->number+1, "is eating");
	philo->eat_count += 1;
	if (philo->eat_count == philo->info->number_of_eat)
		philo->info->im_eat_many_times += 1;
	usleep(philo->info->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_hand);
	pthread_mutex_unlock(philo->left_hand);
}

void pickup_fork(t_philo *philo)
{
	
	pthread_mutex_lock(philo->right_hand);
	print_message(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_hand);
	print_message(philo, "has taken a fork");
}

void *philo(void *argv)
{
	t_philo *philo;

	philo = argv;
	if (philo->number % 2 == 0)
		usleep(philo->info->time_to_eat * 1000);
	while (!philo->info->im_dead)
	{
		pickup_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}