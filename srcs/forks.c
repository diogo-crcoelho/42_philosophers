/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:48:54 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/17 17:22:11 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	change_fork(int n, int flag)
{
	t_timeval	tv;
	int			time;
	t_philo		*philo;

	philo = &env()->philos[n - 1];
	gettimeofday(&tv, NULL);
	time = cut_time(tv) - cut_time(env()->start);
	pthread_mutex_lock(&env()->m_forks[philo->forks[flag]]);
	pthread_mutex_lock(&env()->m_forks[philo->forks[!flag]]);
	env()->l_forks[philo->forks[flag]] = !env()->l_forks[philo->forks[flag]];
	env()->l_forks[philo->forks[!flag]] = !env()->l_forks[philo->forks[!flag]];
	if (env()->l_forks[philo->forks[flag]] && !eaten())
		print_msg(time, n, "has taken a fork");
	if (env()->l_forks[philo->forks[!flag]] && !eaten())
		print_msg(time, n, "has taken a fork");
	pthread_mutex_unlock(&env()->m_forks[philo->forks[!flag]]);
	pthread_mutex_unlock(&env()->m_forks[philo->forks[flag]]);
}

// void    change_fork(int n, int flag)
// {
// 	static int	i;
// 	t_philo		*philo;

// 	philo = &env()->philos[n - 1];
// 	pthread_mutex_lock(&env()->m_forks[philo->forks[flag]]);
//     env()->l_forks[philo->forks[flag]] = !env()->l_forks[philo->forks[flag]];
//     pthread_mutex_unlock(&env()->m_forks[philo->forks[flag]]);
// 	if (++i < 2)
// 		change_fork(n, !flag);
// 	i = 0;
// }

int	av_forks(t_philo *p)
{
	int	a;

	pthread_mutex_lock(&env()->m_forks[p->forks[p->pair]]);
	pthread_mutex_lock(&env()->m_forks[p->forks[!p->pair]]);
	a = (!env()->l_forks[p->forks[0]] && !env()->l_forks[p->forks[1]]);
	pthread_mutex_unlock(&env()->m_forks[p->forks[!p->pair]]);
	pthread_mutex_unlock(&env()->m_forks[p->forks[p->pair]]);
	return (a);
}
