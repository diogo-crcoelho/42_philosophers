/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:59:25 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/17 17:20:27 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	eater(int i)
{
	pthread_mutex_lock(&env()->philos[i].m_eaten);
	if (env()->philos[i].min_eat && env()->min_eat)
		--((env()->philos[i]).min_eat);
	pthread_mutex_unlock(&env()->philos[i].m_eaten);
}

void	check_full(void)
{
	int			i;
	int			full;

	i = -1;
	full = 0;
	while (++i < env()->forks)
	{
		pthread_mutex_lock(&env()->philos[i].m_eaten);
		full = ((env()->philos[i]).min_eat);
		pthread_mutex_unlock(&env()->philos[i].m_eaten);
		if (full)
			return ;
	}
	pthread_mutex_lock(&env()->m_eat);
	env()->feeder = 1;
	pthread_mutex_unlock(&env()->m_eat);
}	
void	p_eat(int i)
{
	t_timeval	tv;
	t_philo		*philo;
	int			time;

	philo = &env()->philos[i - 1];
	change_fork(i, philo->pair);
	gettimeofday(&tv, NULL);
	time = cut_time(tv) - cut_time(env()->start);
	pthread_mutex_lock(&philo->m_ate);
	philo->last_ate = time;
	pthread_mutex_unlock(&philo->m_ate);
	if (!dead_inside() && !eaten())
		print_msg(time, i, "is eating");
	sleeper(env()->tte);
	change_fork(i, philo->pair);
	eater(i - 1);
	// check_full()
}

int	eaten()
{
	int full;
	
	pthread_mutex_lock(&env()->m_eat);
	full = env()->feeder && env()->min_eat;
	pthread_mutex_unlock(&env()->m_eat);
	return (full);
}