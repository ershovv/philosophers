/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:23:06 by bshawn            #+#    #+#             */
/*   Updated: 2022/01/06 15:26:42 by bshawn           ###   ########.fr       */
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

typedef struct s_rule
{
	int				n_ph;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
	int				d;
	struct s_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	output;
	long long		start_time;
	pthread_t		cheack;

}	t_rule;

//Диана самая лучшая <3

typedef struct s_philo
{
	pthread_t	thread;
	t_rule		*rule;
	int			right_fork;
	int			left_fork;
	long long	time_last_eat;
	long long	start_thread_time;
	int			eaten;
	int			dead;
	int			id;

}	t_philo;

int			valid(int argc, char **argv);
int			init(char **argv, t_rule *rule);
int			start(t_rule *rule);
long		ft_atoi(char *c);
void		*life_of_philo(void *p);
long long	time_now(void);
long long	life_time(t_rule *rule, int c);
void		message(t_rule *rule, void *p, char action);
int			all_eat_check(t_rule *rule, t_philo *philo, int *global_eat);
void		my_usleep(long time);

#endif