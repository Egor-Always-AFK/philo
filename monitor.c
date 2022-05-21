#include "philo.h"

void *monitor(void *arg)
{
    t_philo *philo;
    struct  timeval time;
    long long ms;

    philo = arg;
    while (!philo->info->im_dead && (philo->info->im_eat_many_times != philo->info->number_of_philo))
    {
        gettimeofday(&time, NULL);
        //printf("\n\n%d\n\n", philo->info->im_eat_many_times);
        ms = time_to_ms(time) - time_to_ms(philo->last_eat);
        gettimeofday(&time, NULL);
        if (ms >= philo->info->time_to_die && philo->info->im_dead == 0)
        {
            printf("%lld %d %s\n", time_to_ms(time) - time_to_ms(philo->info->create_time), philo->number + 1, "died");
            philo->info->im_dead = 1;
        }
    }
    return (NULL);
}