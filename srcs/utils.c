/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:42:59 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/09 03:19:23 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "gc.h"

int	__isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}
long	cut_time(t_timeval tv)
{
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
void	quit()
{
	while(env()->forks--)
		pthread_mutex_destroy(&env()->m_forks[env()->forks]);
	pthread_mutex_destroy(&env()->m_message);
	pthread_mutex_destroy(&env()->m_dead);	
	gc().end();
}