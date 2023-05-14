/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:59:25 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/14 20:55:49 by dcarvalh         ###   ########.fr       */
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
	if(!dead_inside())
		print_msg(time, i, "is eating");
	sleeper(env()->tte);
	change_fork(i, philo->pair);
	eater(i - 1);
}
int	check_full()
{
    int         i;
	int			full;

	i = -1;	
	full = 0;
	while (++i < env()->forks)
	{
		pthread_mutex_lock(&env()->philos[i].m_eaten);
		full = ((env()->philos[i]).min_eat);
    	pthread_mutex_unlock(&env()->philos[i].m_eaten);
		if (full && env()->min_eat)
			return (1);
			
	}
	return (0 + !(env()->min_eat));
}



// void    check_dead()
// {
//     long        dead;
//     long        autopsy;
// 	t_timeval   tv;

//     gettimeofday(&tv, NULL);
//     dead = cut_time(tv) - cut_time(env()->start);
//     while (++i < env()->forks)
//     {
//         pthread_mutex_lock(&env()->philos[i].m_ate);
//         autopsy = dead - (env()->philos[i]).last_ate;
//         pthread_mutex_unlock(&env()->philos[i].m_ate);
//         if(autopsy > env()->ttd)
//             killer(tv, i + 1);  
//     }
// }