/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:01:07 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/04/18 22:27:38 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"
#include <stdio.h>

t_mem	*init(void);

static void	*__adder(size_t size)
{
	t_trash	*tmp;

	tmp = s_calloc(sizeof (t_trash));
	tmp->content = s_calloc(size);
	tmp->size = size;
	if (!init()->begin)
		init()->begin = tmp;
	else
	{
		tmp->prev = init()->end;
		init()->end->next = tmp;
	}
	init()->end = tmp;
	return (tmp->content);
}

static void	__rem(void *cont)
{
	t_trash	*tmp;
	t_trash	*tmp2;

	tmp = init()->begin;
	while (tmp)
	{
		tmp2 = tmp->next;
		if (cont == tmp->content)
		{
			if (tmp->prev)
				tmp->prev->next = tmp2;
			else
				init()->begin = tmp2;
			if (tmp2)
			tmp2->prev = tmp->prev;
			free(tmp->content);
			free(tmp);
			break ;
		}
		tmp = tmp2;
	}
}

static void	__del(void)
{
	t_trash	*tmp;
	t_trash	*tmp2;

	tmp = init()->begin;
	while (tmp)
	{	
		tmp2 = tmp->next;
		free(tmp->content);
		free(tmp);
		tmp = tmp2;
	}
}

t_gc	gc(void)
{
	static t_gc	tmp = {
		__adder,
		__rem,
		__del
	};

	return (tmp);
}
