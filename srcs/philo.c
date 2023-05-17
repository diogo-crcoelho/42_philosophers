/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:01:13 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/17 17:55:39 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"
#include "philo.h"
#include <stdio.h>
#include <unistd.h>

int		parsing(char **argv);

t_env	*env(void)
{
	static t_env	env;

	return (&env);
}

void	party(int i)
{
	p_eat(i);
	check_full();
	if (eaten())
		return ;
	p_sleep(i);
	usleep(50);
}

void	*phil_loop(void *arg)
{
	t_philo	*p;
	int		t;

	t = 0;
	p = (t_philo *)arg;
	p->pair = p->forks[1] % 2;
	if (p->pair)
		usleep(env()->forks * 3);
	while (!dead_inside() && !eaten())
	{	
		if (av_forks(p))
		{
			party(p->forks[1] + 1);
			t = 0;
		}
		else
		{
			if (!t)
				p_think(p->forks[1] + 1);
			t = 1;
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int	parsed;
	int	i;

	(void)argc;
	i = -1;
	parsed = parsing(argv);
	if (-1 == parsed && printf("Error parsing input!"))
	{
		gc().end();
		return (-1);
	}
	else if (!parsed)
	{
		while (++i < env()->forks)
			pthread_join(env()->philos[i].philo, NULL);
		parsed = !eaten();
	}
	if (dead_inside() && !eaten())
		print_msg((env()->philos[env()->dead - 1]).tod, env()->dead, "died");
	if (!parsed)
		quit();
	gc().end();
	return (0);
}
