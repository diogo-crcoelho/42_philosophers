/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:59:25 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/05 22:44:58 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_eat(t_philo *philo)
{
	long		ini;
	t_timeval	tv;
	int			time;

	ini = env()->start.tv_sec *1000 + env()->start.tv_usec / 1000;
	gettimeofday(&tv, NULL);
	time = (tv.tv_sec *1000 + tv.tv_usec / 1000) - ini;
	philo->last_ate = (tv.tv_sec *1000 + tv.tv_usec / 1000);
	print_msg(time, 0, "is eating");
	sleeper(env()->tte);
}