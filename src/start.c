#include "../includes/philo.h"

void	*life_of_philo(void *p)
{
	t_philo *philo;

	philo = (t_philo *)p;
    while (philo->rule->d)
    {
	    printf("hi by number %d\n", philo->id);
        Usleep(10000000);
    }
	return (0);
}

int end(t_rule *rule)
{
    int i;

    i = 0;
    while (i != rule->n_ph)
    {
        pthread_join(rule->philos[i].thread, NULL);
        i++;
    }
    i = 0;
    while (i != rule->n_ph)
    {
        pthread_mutex_destroy(&rule->forks[i]);
        i++;
    }
    return (1);
}

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
    end(rule);
    return (1);
}
