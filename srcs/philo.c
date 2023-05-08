/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:01:13 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/08 22:56:47 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"
#include "philo.h"
#include <stdio.h>

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
	p_sleep();
	printf("fuckooo%d\n", env()->dead);

	if (env()->dead)
		print_msg((env()->philos[env()->dead - 1]).tod, env()->dead, "has died");
	gc().end();
	return (0);
}
