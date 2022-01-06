/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:32:29 by bshawn            #+#    #+#             */
/*   Updated: 2022/01/06 15:36:40 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	ft_atoi(char *c)
{
	int						i;
	int						checkminus;
	long					res;

	checkminus = 0;
	i = 0;
	res = 0;
	while (((c[i] >= 8) && (c[i] <= 13)) || c[i] == 32)
		i++;
	if (c[i] == '-' || c[i] == '+')
	{	
		if (c[i] == '-')
			checkminus = 1;
		i++;
	}
	while ((c[i] >= '0') && (c[i] <= '9'))
	{
		res = res * 10 + (c[i] - '0');
		i++;
	}
	if (checkminus == 1)
		res = -res;
	return (res);
}

long long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	message(t_rule *rule, void *p, char action)
{
	t_philo		*philo;
	long long	time;

	philo = (t_philo *)p;
	pthread_mutex_lock(&rule->output);
	if (rule->d)
	{
		time = time_now() - rule->start_time;
		printf(" %lli ", time);
		if (action == 't')
			printf("%d is thinking", philo->id + 1);
		if (action == 's')
			printf("%d is sleeping", philo->id + 1);
		if (action == 'f')
			printf("%d has taken a fork", philo->id + 1);
		if (action == 'e')
			printf("%d is eating", philo->id + 1);
		if (action == 'd')
			printf("%d is died", philo->id + 1);
		printf("\n");
	}
	pthread_mutex_unlock(&rule->output);
}

long long	life_time(t_rule *rule, int c)
{
	long	time;

	if (rule->philos[c].time_last_eat)
		time = time_now() - rule->philos[c].time_last_eat;
	else
		time = time_now() - rule->philos[c].start_thread_time;
	return (time);
}

int	all_eat_check(t_rule *rule, t_philo *philo, int *global_eat)
{
	if (rule->must_eat != -1 && philo->eaten == rule->must_eat
		&& philo->eaten != -1)
	{
		*global_eat += 1;
		philo->eaten = -1;
	}
	if (*global_eat == rule->n_ph)
	{
		rule->d = 0;
		printf("vse pokushali\n");
		return (0);
	}
	return (1);
}

void	my_usleep(long time)
{
	long	start;

	start = time_now();
	while (time > time_now() - start)
		usleep(40);
	return ;
}
