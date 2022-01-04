/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:27:16 by bshawn            #+#    #+#             */
/*   Updated: 2022/01/04 12:03:23 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philos(t_rule *rule)
{
	int	i;

	i = 0;
	while (i != rule->n_ph)
	{
		rule->philos[i].id = i;
		rule->philos[i].rule = rule;
		rule->philos[i].left_fork = i;
		rule->philos[i].right_fork = (i + 1) % rule->n_ph;
		rule->philos[i].eaten = 0;
		rule->philos[i].time_last_eat = 0;
		rule->philos[i].start_thread_time = 0;
		i++;
	}
	return (1);
}

int	init_mutex(t_rule *rule)
{
	int	i;

	i = 0;
	while (i != rule->n_ph)
	{
		if (pthread_mutex_init(&rule->forks[i], NULL))
			return (0);
		i++;
	}
	if (pthread_mutex_init(&rule->output, NULL))
		return (0);
	return (1);
}

int	init(char **argv, t_rule *rule)
{
	rule->d = 1;
	rule->n_ph = ft_atoi(argv[1]);
	rule->t_die = ft_atoi(argv[2]);
	rule->t_eat = ft_atoi(argv[3]);
	rule->t_sleep = ft_atoi(argv[4]);
	rule->start_time = 0;
	if (argv[5])
		rule->must_eat = ft_atoi(argv[5]);
	else
		rule->must_eat = -1;
	rule->philos = malloc(sizeof(t_philo) * rule->n_ph);
	if (!rule->philos)
		return (0);
	rule->forks = malloc(sizeof(pthread_mutex_t) * rule->n_ph);
	if (!rule->forks)
		return (0);
	if (!init_philos(rule))
		return (0);
	if (!init_mutex(rule))
		return (0);
	return (1);
}
