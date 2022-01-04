/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:39:35 by bshawn            #+#    #+#             */
/*   Updated: 2022/01/04 12:05:48 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	else
		return (0);
}

int	check_rule(char **argv)
{
	if ((ft_atoi(argv[1]) < 2) || (ft_atoi(argv[2]) < 0)
		|| (ft_atoi(argv[3]) < 0) || (ft_atoi(argv[4]) < 0))
		return (0);
	if (argv[5])
	{
		if (ft_atoi(argv[5]) <= 0)
			return (0);
	}
	return (1);
}

int	valid(int argc, char **argv)
{
	int	i;
	int	k;

	if (argc != 5 && argc != 6)
		return (0);
	k = 1;
	while (argv[k])
	{
		i = 0;
		while (argv[k][i])
		{
			if (!ft_isdigit(argv[k][i]))
				return (0);
			if (i > 8)
				return (0);
			i++;
		}
		k++;
	}
	if (!check_rule(argv))
		return (0);
	return (1);
}
