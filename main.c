/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:17:50 by bshawn            #+#    #+#             */
/*   Updated: 2021/10/10 16:14:42 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	*life_of_philo(void *p)
{
	t_philo *philo;

	philo = (t_philo *)p;
	printf("hi by number %d\n", philo->id);
	return (0);
}

int	main(int argc, char **argv)
{
	t_rule	rule;

	if (!(valid(argc, argv)))
	{
		printf("bad valid\n");
		return (0);
	}
	
	if (!(init(argv, &rule)))
	{
		printf("bad init\n");
		return (0);
	}
	sleep(1);
	return (0);
}
