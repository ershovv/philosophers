/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:17:50 by bshawn            #+#    #+#             */
/*   Updated: 2022/01/06 19:19:43 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	my_usleep(long time)
{
	long	start;

	start = time_now();
	while (time > time_now() - start)
		usleep(40);
	return ;
}

void	error(int code)
{
	if (code == 1)
	{
		printf("bad valid\n");
		exit(1);
	}
	if (code == 2)
	{
		printf("bad init\n");
		exit(1);
	}
	if (code == 3)
	{
		printf("bad start\n");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_rule	rule;

	if (!(valid(argc, argv)))
		error(1);
	if (!(init(argv, &rule)))
		error(2);
	if (!start(&rule))
		error(3);
	printf("END\n");
	free(rule.philos);
	free(rule.forks);
	return (0);
}
