/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:00:53 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/04/20 20:57:25 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"
#include <unistd.h>

static size_t	digit_count(long int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
	{
		++i;
		n *= -1;
	}
	while (n > 0)
	{
		++i;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*res;
	size_t		size;
	long int	temp;

	temp = (long)n;
	size = digit_count(temp);
	res = (char *)gc().add(size + 1);
	if (!res)
		return (NULL);
	res[size] = 0;
	if (temp == 0)
		res[0] = 48;
	if (temp < 0)
	{
		res[0] = '-';
		temp *= -1;
	}
	while (temp > 0)
	{
		res[--size] = temp % 10 + 48;
		temp /= 10;
	}
	return (res);
}

//Meter esta merda em recursiva;

void	print_msg(int time, int phil, char *action)
{
	char	*s_time;
	char	*s_phil;
	char	*msg;

	s_time = ft_itoa(time);
	s_phil = ft_itoa(phil);
	msg = s().join(s_time, s_phil, " ");
	msg = s().join(msg, action, " ");
	write(1, msg, s().len(msg, 0));
	gc().remove(msg);
	gc().remove(s_phil);
	gc().remove(s_time);
}
