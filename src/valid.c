/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:39:35 by bshawn            #+#    #+#             */
/*   Updated: 2021/09/18 16:55:54 by bshawn           ###   ########.fr       */
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
			i++;
		}
		k++;
	}
	return (1);
}
