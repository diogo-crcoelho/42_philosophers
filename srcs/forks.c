/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:48:54 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/09 07:35:20 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    change_fork(int n)
{
	static int	i;
	t_philo		*philo;
	
	philo = &env()->philos[n - 1];
	pthread_mutex_lock(&env()->m_forks[philo->forks[i]]);
    env()->l_forks[philo->forks[i]] = !env()->l_forks[philo->forks[i]];
    pthread_mutex_unlock(&env()->m_forks[philo->forks[i++]]);
	if (i < 2)
		change_fork(n);
	i = 0;
}
