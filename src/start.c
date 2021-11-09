#include "../includes/philo.h"

void eating(void *p)
{
	t_philo *philo;
	t_rule	*rule;

	philo = (t_philo *)p;
	rule = philo->rule;

	pthread_mutex_lock(&(rule->forks[philo->left_fork]));
	message(rule, philo, 'f');
	pthread_mutex_lock(&(rule->forks[philo->right_fork]));
	message(rule, philo, 'f');

	message(rule, philo, 'e');
	usleep(philo->rule->t_eat * 1000);
	philo->eaten += 1;

	pthread_mutex_unlock(&(rule->forks[philo->left_fork]));
	pthread_mutex_unlock(&(rule->forks[philo->right_fork]));	
}

void	*life_of_philo(void *p)
{
	t_philo *philo;
	philo = (t_philo *)p;

	if (philo->id % 2)
		usleep(15);

	while (philo->rule->d)
	{
		eating(philo);
		message(philo->rule, philo, 's');
		usleep(philo->rule->t_sleep);
		message(philo->rule, philo, 't');
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
	rule->start_time = time_now();
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
