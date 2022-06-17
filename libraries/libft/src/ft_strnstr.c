/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:35:00 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/12 20:23:29 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needlen;
	size_t	j;

	needlen = ft_strlen(needle);
	j = 0;
	if (ft_strlen(haystack) < len)
		len = ft_strlen(haystack);
	while (j + needlen <= len)
	{
		if (ft_strncmp((haystack + j), needle, needlen) != 0)
			++j;
		else
			return ((char *)haystack + j);
	}
	return (NULL);
}
