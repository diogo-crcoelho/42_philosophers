/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:03:29 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/08 23:19:57 by dcarvalh         ###   ########.fr       */
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
	goal = cut_time(tv) + time;
	while (cut_time(tv) < goal && !env()->dead)
	{
		gettimeofday(&tv, NULL);
		check_dead();
		usleep(100);
	}
}

void	p_sleep(int i)
{
	long		ini;
	t_timeval	tv;
	int			time;

	ini = cut_time(env()->start);
	gettimeofday(&tv, NULL);
	time = cut_time(tv) - ini;
	if (!env()->dead)
		print_msg(time, i, "is sleeping");
	sleeper(env()->tts);
}
