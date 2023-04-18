/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:55:39 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/02/26 15:53:30 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

# include <stdlib.h>

typedef struct s_trash{
	void			*content;
	int				size;
	struct s_trash	*next;
	struct s_trash	*prev;
}	t_trash;

typedef struct s_mem{
	t_trash	*begin;
	t_trash	*end;
}	t_mem;

typedef struct t_gc{
	void	*(*create)(size_t);
	void	(*remove)(void *);
	void	(*end)(void);
}	t_gc;

void	*s_calloc(size_t size);
int		ft_memcmp(const void *str1, const void *str2, size_t n);

t_gc	gc(void);

#endif