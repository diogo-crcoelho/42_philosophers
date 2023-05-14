/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:07:38 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/14 19:10:15 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    killer(t_timeval tv, int i)
{   
    if (!dead_inside())
    {
        pthread_mutex_lock(&env()->m_dead);
        env()->dead = i;
        pthread_mutex_unlock(&env()->m_dead);
        (env()->philos[i - 1]).tod = cut_time(tv) - cut_time(env()->start);
    }
}
void    check_dead()
{
    int         i;
    long        dead;
    long        autopsy;
	t_timeval   tv;

    i = -1;
    gettimeofday(&tv, NULL);
    dead = cut_time(tv) - cut_time(env()->start);
    while (++i < env()->forks)
    {
        pthread_mutex_lock(&env()->philos[i].m_ate);
        autopsy = dead - (env()->philos[i]).last_ate;
        pthread_mutex_unlock(&env()->philos[i].m_ate);
        if(autopsy > env()->ttd)
            killer(tv, i + 1);  
    }
}
int	dead_inside()
{
	int a;

	pthread_mutex_lock(&env()->m_dead);
	a = env()->dead;
    pthread_mutex_unlock(&env()->m_dead);
	return (a);
}
