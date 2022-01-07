/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:05:56 by bshawn            #+#    #+#             */
/*   Updated: 2022/01/07 16:30:18 by bshawn           ###   ########.fr       */
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
	int		status;
	int		i;

	i = 0;
	while (i <= rule->n_ph)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = 0;
			while (i <= rule->n_ph)
			{
				kill(rule->philos[i].pid, 15);
				i++;
			}
		}
		i++;
	}
	sem_close(rule->output);
	sem_close(rule->forks);
	sem_close(rule->death);
	sem_unlink("/death");
	sem_unlink("/forks");
	sem_unlink("/output");
	return (1);
}

void	*death_check(void *phi)
{
	t_rule		*rule;
	t_philo		*philo;
	long long	time;
	int			i;

	philo = (t_philo *) phi;
	rule = philo->rule;
	i = 0;
	while (1)
	{
		time = life_time(philo);
		if ((long long)rule->t_die <= time)
		{
			message(rule, &rule->philos[i], 'd');
			rule->d = 0;
			return (NULL);
		}
		usleep(50);
		i++;
	}
	return (NULL);
}

void	proc(void *ptr_philo)
{
	t_philo	*philo;

	philo = (t_philo *) ptr_philo;
	pthread_create(&(philo->cheack), NULL, death_check, ptr_philo);
	philo->start_thread_time = time_now();
	if (philo->id % 2)
		usleep(150);
	while (philo->rule->d)
	{
		eating(philo);
		message(philo->rule, philo, 's');
		my_usleep(philo->rule->t_sleep);
		message(philo->rule, philo, 't');
	}
	write(2, "check\n", 6);
	pthread_join(philo->cheack, NULL);
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
			proc(&(philos[i]));
		usleep(150);
		i++;
	}
	end(rule);
	return (0);
}
