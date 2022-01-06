/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:05:56 by bshawn            #+#    #+#             */
/*   Updated: 2022/01/06 20:48:29 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating(void *p)
{
	t_philo	*philo;
	t_rule	*rule;

	philo = (t_philo *)p;
	rule = philo->rule;
	sem_wait(rule->forks);
	message(rule, philo, 'f');
	sem_wait(rule->forks);
	message(rule, philo, 'f');
	message(rule, philo, 'e');
	my_usleep(philo->rule->t_eat);
	philo->time_last_eat = time_now();
	sem_post(rule->forks);
	sem_post(rule->forks);
	philo->eaten += 1;
}

int	end(t_rule *rule)
{
	int	status;
	int	i;

	i = 0;
	while (rule->philos[i])
	{
		waitpid(rule->philos[i].pid, &status, -1);
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

void	proc(void *ptr_philo)
{
	t_rule	*rule;
	t_philo	*philo;

	philo = (t_philo *) ptr_philo;
	rule = philo->rule;
	pthread_create(&(rule->cheack), NULL, death_check, rule);
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
	pthread_join(rule->cheack, NULL);
	exit(0);
}

int	start(t_rule *rule)
{
	int		i;
	t_philo	*philos;

	philos = rule->philos;
	i = 0;
	rule->start_time = time_now();
	while (i != rule->n_ph)
	{
		philos[i].pid = fork();
		if (philos[i].pid < 0)
			return (1);
		if (philos[i].pid == 0)
			
		usleep(50);
		i++;
	}
	end(rule);
	return (0);
}
