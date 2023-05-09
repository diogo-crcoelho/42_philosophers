/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:01:13 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/09 09:24:54 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"
#include "philo.h"
#include <stdio.h>
#include <unistd.h>


void    change_fork(int n);

int		parsing(char **argv);

t_env	*env(void)
{
	static t_env	env;

	return (&env);
}

void	*phil_loop(void *arg)
{
	t_philo *p;
	int		t;
	
	t = 0;
	p = (t_philo *)arg;
	if (p->forks[1] % 2 != 0)
		usleep(100);
	while(!env()->dead)
	{		
	if (!env()->l_forks[p->forks[0]] && !env()->l_forks[p->forks[1]])
	{
		p_eat(p->forks[1] + 1);
		p_sleep(p->forks[1] + 1);
		t = 0;
	}
	else
	{
		if (!t)
			p_think(p->forks[1] + 1);
		usleep(50);
		t = 1;
	}
	}
	return NULL;
}
int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (parsing(argv) && printf("Error parsing input!"))
	{
		gc().end();
		return (-1);
	}
	for (int i = 0; i < env()->forks; i++)
		pthread_join(env()->philos[i].philo, NULL);
	if (env()->dead)
		print_msg((env()->philos[env()->dead - 1]).tod, env()->dead, "has died");
	quit();
	return (0);
}
