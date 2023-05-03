/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:00:59 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/03 19:36:36 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "philo.h"
#include "ft_strings.h"

int	__isdigit(int c);

int	s_atoi(char *str)
{
	int	old;
	long	val;
	int		i;

	i = -1;
	val = 0;
	if (!s().len(str, 0))
        return (0);
	if (s().contains(str, "-"))
        return (0);
	while (str && str[++i])
	{
		old = val;
		val = val * 10 + (str[i] - 48);
		if (val < old || !__isdigit(str[i]))
            return (0);
	}
	return (val);
}
#include <stdio.h>
void	init_philos(int n)
{
	env()->philos = gc().add((n + 1) * sizeof(t_philo));
	while (n--)
		(env()->philos[n]).min_eat = env()->min_eat;
}

int parsing(char **argv)
{
	env()->forks = s_atoi(argv[1]);
    env()->ttd = s_atoi(argv[2]);
    env()->tte = s_atoi(argv[3]);
    env()->tts = s_atoi(argv[4]);
    env()->min_eat = s_atoi(argv[5]);
	if (!env()->forks)
		return (-1);
	init_philos(env()->forks);
    if (!env()->ttd || !env()->tte || !env()->tts)
        return (-1);
    return (0);
}
