/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:15:23 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/31 13:57:25 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	lens;

	lens = ft_strlen(s1);
	ptr = malloc(lens + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[lens] = '\0';
	ft_strlcpy(ptr, s1, lens + 1);
	return (ptr);
}
