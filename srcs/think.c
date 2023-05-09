/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:16:13 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/09 00:19:39 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    p_think(int i)
{
    long		ini;
	t_timeval	tv;
	int			time;

	ini = cut_time(env()->start);
	gettimeofday(&tv, NULL);
	time = cut_time(tv) - ini;
	if (!env()->dead)
		print_msg(time, i, "is thinking");
}
