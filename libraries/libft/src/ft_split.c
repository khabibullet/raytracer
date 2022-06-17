/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:32:15 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/13 15:37:28 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_strcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s)
				s++;
			count++;
		}
		else
			s++;
	}
	return (count);
}

static int	newstr(char	**spl, const char	*s, char c, size_t	count)
{
	size_t	i;

	*(spl + count) = NULL;
	i = count;
	while (i)
	{
		count = 0;
		while (*s == c)
			s++;
		while (*(s + count) != c && *(s + count) != '\0')
			count++;
		if (*s)
		{
			*spl = (char *)malloc(sizeof(char) * (count + 1));
			if (!*spl)
				return (0);
			ft_strlcpy(*spl, s, count + 1);
		}
		if (!count)
			return (0);
		s = s + count;
		spl++;
		i--;
	}
	return (1);
}

char	**ft_split(char	const	*s, char c)
{
	char	**spl;
	size_t	count;

	if (!s)
		return (NULL);
	if (*s == '\0')
		count = 0;
	else
		count = ft_strcount(s, c);
	spl = (char **)malloc(sizeof(char *) * (count + 1));
	if (!spl)
		return (NULL);
	if (!newstr(spl, s, c, count))
		return (NULL);
	return (spl);
}
