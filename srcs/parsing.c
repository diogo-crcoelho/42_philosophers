/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:00:59 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/16 01:12:55 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"
#include "philo.h"
#include <limits.h>
#include <unistd.h>

int		__isdigit(int c);
void	*phil_loop(void *arg);

int	s_atoi(char *str)
{
	int		old;
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

void	init_philos(int n)
{
	env()->philos = gc().add(n * sizeof(t_philo));
	env()->l_forks = gc().add(n * sizeof(int));
	env()->m_forks = gc().add(n * sizeof(pthread_mutex_t));
	while (n--)
	{
		pthread_mutex_init(&env()->m_forks[n], NULL);
		(env()->philos[n]).min_eat = env()->min_eat;
		(env()->philos[n]).forks[0] = n - 1;
		(env()->philos[n]).forks[1] = n;
		(env()->philos[0]).forks[0] = env()->forks - 1;
	}
	while (++n < env()->forks)
		pthread_create(&((env()->philos[n]).philo), NULL, phil_loop, \
		&(env()->philos[n]));
}

int	parsing(char **argv)
{
	env()->forks = s_atoi(argv[1]);
	env()->ttd = s_atoi(argv[2]);
	env()->tte = s_atoi(argv[3]);
	env()->tts = s_atoi(argv[4]);
	env()->min_eat = s_atoi(argv[5]);
	if (!env()->forks)
		return (-1);
	if (!env()->ttd || !env()->tte || !env()->tts)
		return (-1);
	pthread_mutex_init(&env()->m_message, NULL);
	pthread_mutex_init(&env()->m_dead, NULL);
	gettimeofday(&env()->start, NULL);
	if (1 == env()->forks)
	{
		env()->philos = gc().add(sizeof(t_philo));
		print_msg(0, 1, "has taken a fork");
		p_think(1);
		sleeper(env()->ttd + 10);
		return (-2);
	}
	init_philos(env()->forks);
	return (0);
}
