/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:01:13 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/04 18:46:55 by dcarvalh         ###   ########.fr       */
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
	sleeper();
	sleeper();
	sleeper();
	sleeper();
	gc().end();
	return (0);
}
