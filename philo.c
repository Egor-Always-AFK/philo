# include "philo.h"

void thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->print_mutex);
	print_message(philo, "is thinking");
	pthread_mutex_unlock(&philo->info->print_mutex);
}

void sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->print_mutex);
	print_message(philo, "is sleeping");
	pthread_mutex_unlock(&philo->info->print_mutex);
	ft_usleep(philo->info->time_to_sleep);
}

void eating(t_philo *philo)
{
	long long ms;

	pthread_mutex_lock(&philo->check_mutex);
	pthread_mutex_lock(&philo->info->finish_mutex);
	if (!philo->info->im_dead)
	{
		gettimeofday(&philo->last_eat, NULL);
		pthread_mutex_lock(&philo->info->print_mutex);
		printf("%ld %d %s\n", time_to_ms(philo->last_eat) - time_to_ms(philo->info->create_time), philo->number + 1, "is eating");
		pthread_mutex_unlock(&philo->info->print_mutex);
	}
	philo->eat_count += 1;
	if (philo->info->number_of_eat != 0 && (philo->eat_count == philo->info->number_of_eat))
		philo->info->im_eat_many_times += 1;
	pthread_mutex_unlock(&philo->info->finish_mutex);
	ft_usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->right_hand);
	pthread_mutex_unlock(philo->left_hand);
	pthread_mutex_unlock(&philo->check_mutex);
}

void pickup_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_hand);
	pthread_mutex_lock(&philo->info->print_mutex);
	print_message(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->info->print_mutex);
	pthread_mutex_lock(philo->left_hand);
	pthread_mutex_lock(&philo->info->print_mutex);
	print_message(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->info->print_mutex);
}

void *philo(void *argv)
{
	t_philo *philo;

	philo = argv;
	//gettimeofday(&philo->last_eat, NULL);
	if (philo->number % 2 == 0)
		usleep(2500);
	while (!philo->info->im_dead)
	{
		pickup_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}