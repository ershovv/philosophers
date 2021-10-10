/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:27:16 by bshawn            #+#    #+#             */
/*   Updated: 2021/10/10 16:02:23 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init(char **argv, t_rule *rule)
{
	rule->n_ph = ft_atoi(argv[1]);
	rule->t_die = ft_atoi(argv[2]);
	rule->t_eat = ft_atoi(argv[3]);
	rule->t_sleep = ft_atoi(argv[4]);
	rule->philos = malloc(sizeof(t_philo) * rule->n_ph);
	if (!rule->philos)
		return (0);
	return (1);
}
