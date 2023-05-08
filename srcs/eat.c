/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:59:25 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/08 23:21:53 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_eat(int i)
{
	t_timeval	tv;
	t_philo		*philo;
	int			time;

	philo = &env()->philos[i - 1];
	gettimeofday(&tv, NULL);
	time = cut_time(tv) - cut_time(env()->start);
	philo->last_ate = time + env()->tte;
	print_msg(time, i, "is eating");
	sleeper(env()->tte);
}