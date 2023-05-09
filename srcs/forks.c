/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:48:54 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/09 02:55:06 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    change_fork(int n)
{
    int left;
    int right;

    left = env()->philos[n - 1].forks[0];
    right = env()->philos[n - 1].forks[1];
    pthread_mutex_lock(&env()->m_forks[left]);
    pthread_mutex_lock(&env()->m_forks[right]);
    env()->l_forks[left] = !env()->l_forks[left];
    env()->l_forks[right] = !env()->l_forks[right];
    pthread_mutex_unlock(&env()->m_forks[right]); 
    pthread_mutex_unlock(&env()->m_forks[left]);
}
