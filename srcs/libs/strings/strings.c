/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:12:25 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/04/18 21:13:50 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char		**__ft_split(const char *str, int sep);
int			__str_len(const char *str, int sep);
char		*__strn_dup(const char *str, int size);
int			__strn_cmp(const char *str1, const char *str2, unsigned long n);
int			__strn_str(const char *haystack, const char *needle);
char		*__str_trim(const char *str);
char		*__str_join(const char *s1, const char *s2, const char *sep);

static char	*__str_dup(const char *str)
{
	int		size;
	char	*ret;

	size = __str_len(str, 0);
	ret = gc().add(size + 1);
	while (size--)
		ret[size] = str[size];
	return (ret);
}

int	__str_cmp(const char *str1, const char *str2)
{
	int	i;

	i = -1;
	if (str1 && str2)
		while (str1[++i] || str2[i])
			if (str1[i] != str2[i])
				return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	return (0);
}

static int	check_size(const char *str)
{
	int	size;
	int	i;

	if (!str)
		return (0);
	size = __str_len(str, 0);
	i = 0;
	while (str[i] && ' ' == str[i])
		++i;
	while (' ' == str[size - 1])
		size --;
	return (size - i);
}

char	*__str_trim(const char *str)
{
	int		size;
	char	*res;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	size = check_size(str);
	res = gc().add(size + 1);
	i = 0;
	j = -1;
	while (str[i] && ' ' == str[i])
		++i;
	while (++j < size)
		res[j] = str[i + j];
	return (res);
}

t_strings	s(void)
{
	static t_strings	string = {
		__str_len,
		__str_dup,
		__strn_dup,
		__ft_split,
		__str_cmp,
		__strn_cmp,
		__strn_str,
		__str_trim,
		__str_join
	};

	return (string);
}
