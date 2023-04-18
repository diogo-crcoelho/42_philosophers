/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:38:24 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/04/18 21:08:10 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

int	__str_len(const char *str, int sep)
{
	int	i;

	i = 0;
	while (str && str[i] && sep != str[i])
		++i;
	return (i);
}

int	__strn_cmp(const char *str1, const char *str2, int n)
{
	int	i;

	i = -1;
	if (str1 && str2)
		while (++i < n && (str1[i] || str2[i]))
			if (str1[i] != str2[i])
				return ((unsigned char )str1[i] - (unsigned char )str2[i]);
	return (0);
}

int	__strn_str(const char *haystack, const char *needle)
{
	int	i;
	int	size_small;
	int	size_big;

	if (!needle || !haystack)
		return (0);
	i = -1;
	size_small = __str_len(needle, 0);
	size_big = __str_len(haystack, 0);
	if (size_big >= size_small)
	{	
		while (++i <= size_big - size_small)
		{
			if (!__strn_cmp(&haystack[i], needle, size_small))
				return (1);
		}
	}
	return (0);
}

char	*__strn_dup(const char *str, int size)
{
	char	*ret;

	if (__str_len(str, 0) < size)
		size = __str_len(str, 0);
	ret = gc().add(size + 1);
	while (size--)
		ret[size] = str[size];
	return (ret);
}

char	**__ft_split(const char *str, int sep)
{
	char		**strings;
	static int	size;
	int			i;
	char		*word;

	i = 0;
	word = NULL;
	while (*str && sep == *str)
		str++;
	i = __str_len(str, sep);
	if (i)
		word = __strn_dup(str, i);
	if (word && ++size)
		strings = __ft_split(str + i, sep);
	else
		strings = (char **)gc().add((size + 1) * sizeof(char *));
	strings[size--] = word;
	if (size < 0)
		++size;
	return (strings);
}
