#include "philo.h"

void *monitor(void *arg)
{
    t_philo *philo;
    struct  timeval time;
    long long ms;

    philo = arg;
    while (!philo->info->im_dead)
    {
        gettimeofday(&time, NULL);
        ms = time_to_ms(time) - time_to_ms(philo->last_eat);
        gettimeofday(&time, NULL);
        if (ms >= philo->info->time_to_die && philo->info->im_dead == 0)
        {
            printf("%lld\t%d\t %s\n", time_to_ms(time) - time_to_ms(philo->info->create_time), philo->number + 1, "died");
            philo->info->im_dead = 1;
        }
    }
    return (NULL);
}