/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:01:13 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/04/18 21:44:47 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "gc.h"

int parsing(char **argv);

t_env	*env()
{
	static t_env env;

	return (&env);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	if (!parsing(argv))
		printf("%d-%d-%d-%d\n", env()->ttd, env()->tte, env()->tts, env()->min_eat);
	else
		err_handle("Error parsing input!");
	gc().end();
	return (0);
}
