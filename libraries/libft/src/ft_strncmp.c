/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:25:30 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/25 16:44:05 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		dif;
	size_t	slen_1;
	size_t	slen_2;

	dif = 0;
	i = 0;
	slen_1 = ft_strlen(s1);
	slen_2 = ft_strlen(s2);
	if (slen_1 > slen_2)
		slen_2 = slen_1;
	while (i < n && (dif == 0) && i < slen_2)
	{
		dif = (unsigned char)s1[i] - (unsigned char)s2[i];
		++i;
	}
	return (dif);
}
