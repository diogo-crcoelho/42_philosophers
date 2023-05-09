/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:59:25 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/09 09:16:48 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_eat(int i)
{
	t_timeval	tv;
	t_philo		*philo;
	int			time;

	change_fork(i);
	philo = &env()->philos[i - 1];
	gettimeofday(&tv, NULL);
	time = cut_time(tv) - cut_time(env()->start);
	philo->last_ate = time + env()->tte;
	if(!env()->dead)
		print_msg(time, i, "is eating");
	sleeper(env()->tte);
	change_fork(i);
	
}