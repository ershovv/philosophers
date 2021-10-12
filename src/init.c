/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:27:16 by bshawn            #+#    #+#             */
/*   Updated: 2021/10/10 16:14:50 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philos(t_rule *rule)
{
	int	i;

	i = 0;
	while (i != rule->n_ph)
	{
		rule->philos[i].id = i + 1;
		pthread_create(&rule->philos[i].thread, NULL, life_of_philo, &rule->philos[i]);
		i++;
	}
	return (1);
}

int	init(char **argv, t_rule *rule)
{
	rule->n_ph = ft_atoi(argv[1]);
	rule->t_die = ft_atoi(argv[2]);
	rule->t_eat = ft_atoi(argv[3]);
	rule->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		rule->must_eat = ft_atoi(argv[5]);
	else
		rule->must_eat = -1;
	rule->philos = malloc(sizeof(t_philo) * rule->n_ph);
	if (!rule->philos)
		return (0);
	init_philos(rule);
	sleep(7);
	return (1);
}
