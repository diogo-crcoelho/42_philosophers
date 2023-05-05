/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:03:29 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/05 22:00:45 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

void	sleeper(int time)
{
	
	t_timeval	tv;
	long 		goal;

	gettimeofday(&tv, NULL);
	goal = (tv.tv_sec * 1000 + tv.tv_usec / 1000) + time;
	while (tv.tv_sec * 1000 + tv.tv_usec / 1000 < goal)
	{
		gettimeofday(&tv, NULL);
		usleep(100);
	}
}

void	p_sleep()
{
	long		ini;
	t_timeval	tv;
	int			time;

	ini = env()->start.tv_sec *1000 + env()->start.tv_usec / 1000;
	gettimeofday(&tv, NULL);
	time = (tv.tv_sec *1000 + tv.tv_usec / 1000) - ini;
	print_msg(time, 0, "is sleeping");
	sleeper(env()->tts);
}