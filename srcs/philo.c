/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:01:13 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/09 02:56:57 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"
#include "philo.h"
#include <stdio.h>


void    change_fork(int n);

int		parsing(char **argv);

t_env	*env(void)
{
	static t_env	env;

	return (&env);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (parsing(argv))
		err_handle("Error parsing input!");
	else
	{
		gettimeofday(&env()->start, NULL);
	}
	p_eat(1);
	p_eat(1);
	change_fork(1);
	printf("%d\n", env()->l_forks[0]);
	if (env()->dead)
		print_msg((env()->philos[env()->dead - 1]).tod, env()->dead, "has died");
	gc().end();
	return (0);
}
