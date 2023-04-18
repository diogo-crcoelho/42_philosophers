/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:03:00 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/04/18 21:17:31 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

int	__str_len(const char *str, int sep);

char	*__str_join(const char *s1, const char *s2, const char *sep)
{
	char	*new;
	int		i;
	int		j;

	new = gc().add(__str_len(s1, 0) + __str_len(s2, 0) + __str_len(sep, 0) + 1);
	i = -1;
	while (++i < __str_len(s1, 0))
		new[i] = s1[i];
	j = -1;
	while (++j < __str_len(sep, 0))
		new[i++] = sep[j];
	j = -1;
	while (++j < __str_len(s2, 0))
		new[i++] = s2[j];
	return (new);
}
