/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:00:59 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/04/18 21:27:36 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "philo.h"
#include "ft_strings.h"

int	__isdigit(int c);

long	s_atoi(char *str)
{
	long	old;
	long	val;
	int		signal;
	int		i;

	i = -1;
	val = 0;
	signal = 1;
	if (!s().len(str, 0))
		err_handle("Error parsing input!");
	if (!s().equal(str, "-9223372036854775808"))
		return (LONG_MIN);
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			signal *= -1;
	while (str && str[++i])
	{
		old = val;
		val = val * 10 + (str[i] - 48);
		if (val < old || !__isdigit(str[i]))
        {
			err_handle("Error parsing input!");
            break ;
        }
	}
	return (val * signal);
}

int parsing(char **argv)
{
    (void)argv;
    return (0);
}
