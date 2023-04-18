/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:12:40 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/04/18 16:05:27 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRINGS_H
# define FT_STRINGS_H

# include "gc.h"

typedef struct s_strings
{
	int					(*len)(const char *, int);
	char				*(*copy)(const char *);
	char				*(*copy_n)(const char *, int);
	char				**(*split)(const char *, int);
	int					(*equal)(const char *, const char *);
	int					(*equal_n)(const char *, const char *, size_t);
	int					(*contains)(const char *, const char *);
	char				*(*trim)(const char *);
}	t_strings;

t_strings	s(void);

#endif