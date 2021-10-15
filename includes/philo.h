/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:23:06 by bshawn            #+#    #+#             */
/*   Updated: 2021/10/10 16:01:39 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t	thread;
	// t_rule		*rule;
	int			right_fork;
	int			left_fork;
	int			dead;
	int			id;

}	t_philo;

typedef struct s_rule
{
	int				n_ph;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
	t_philo			*philos;
	pthread_mutex_t *forks;

}	t_rule;

int		valid(int argc, char **argv);
int		init(char **argv, t_rule *rule);
int		start(t_rule *rule);
long	ft_atoi(char *c);
void	*life_of_philo(void *p);
void	error(int code);

#endif