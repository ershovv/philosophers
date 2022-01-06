/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:05:56 by bshawn            #+#    #+#             */
/*   Updated: 2022/01/06 15:30:29 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating(void *p)
{
	t_philo	*philo;
	t_rule	*rule;

	philo = (t_philo *)p;
	rule = philo->rule;
	pthread_mutex_lock(&(rule->forks[philo->left_fork]));
	message(rule, philo, 'f');
	pthread_mutex_lock(&(rule->forks[philo->right_fork]));
	message(rule, philo, 'f');
	message(rule, philo, 'e');
	my_usleep(philo->rule->t_eat);
	philo->time_last_eat = time_now();
	philo->eaten += 1;
	pthread_mutex_unlock(&(rule->forks[philo->left_fork]));
	pthread_mutex_unlock(&(rule->forks[philo->right_fork]));
}

void	*life_of_philo(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	philo->start_thread_time = time_now();
	if (philo->id % 2)
		usleep(50);
	while (philo->rule->d)
	{
		eating(philo);
		message(philo->rule, philo, 's');
		my_usleep(philo->rule->t_sleep);
		message(philo->rule, philo, 't');
	}
	return (0);
}

int	end(t_rule *rule)
{
	int	i;

	i = 0;
	while (i != rule->n_ph)
	{
		pthread_mutex_destroy(&rule->forks[i]);
		i++;
	}
	return (1);
}

void	*death_check(void *r)
{
	t_rule		*rule;
	long long	time;
	int			i;
	int			eat;

	i = 0;
	eat = 0;
	rule = (t_rule *) r;
	while (1)
	{
		if (i == rule->n_ph)
			i = 0;
		time = life_time(rule, i);
		if ((long long)rule->t_die <= time)
		{
			message(rule, &rule->philos[i], 'd');
			rule->d = 0;
			return (NULL);
		}
		if (!(all_eat_check(rule, &rule->philos[i], &eat)))
			return (NULL);
		usleep(50);
		i++;
	}
}

int	start(t_rule *rule)
{
	int	i;

	i = 0;
	rule->start_time = time_now();
	while (i != rule->n_ph)
	{
		if (pthread_create(&(rule->philos[i].thread), NULL,
				life_of_philo, &rule->philos[i]))
			return (0);
		usleep(50);
		i++;
	}
	pthread_create(&(rule->cheack), NULL, death_check, rule);
	pthread_join(rule->cheack, NULL);
	return (1);
}
