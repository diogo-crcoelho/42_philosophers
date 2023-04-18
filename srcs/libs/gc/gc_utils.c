/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:52:16 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/02/26 16:15:12 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

t_mem	*init(void)
{
	static t_mem	root;

	return (&root);
}

void	*s_calloc(size_t size)
{
	void	*tmp;

	tmp = malloc(size);
	if (!tmp)
		exit(1);
	while (size--)
		((char *)tmp)[size] = 0;
	return (tmp);
}

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = -1;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (++i < n)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (0);
}
