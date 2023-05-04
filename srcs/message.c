/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:00:53 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/04 18:44:25 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	print_msg(int time, int phil, char *action)
{
	pthread_mutex_lock(&env()->m_message);
	printf("%d %d %s\n", time, phil, action);
	pthread_mutex_unlock(&env()->m_message);
}
