/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:07:38 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/08 23:26:03 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    killer(t_timeval tv, int i)
{   
    if (!env()->dead)
    {
        pthread_mutex_lock(&env()->m_dead);
        env()->dead = i;
        (env()->philos[i - 1]).tod = cut_time(tv) - cut_time(env()->start);
        pthread_mutex_unlock(&env()->m_dead);
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
        autopsy = dead - (env()->philos[i]).last_ate;
        if(autopsy > env()->ttd)
            killer(tv, i + 1);  
    }
}
