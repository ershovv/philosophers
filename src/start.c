#include "../includes/philo.h"

int start(t_rule *rule)
{
    int i;

    i = 0;
    while (i != rule->n_ph)
    {
        if (pthread_create(&(rule->philos[i].thread), NULL,
            life_of_philo, &rule->philos[i]))
            return (0);
        i++;
    }
    return (1);
}
