/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:23:45 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/12 20:22:12 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	m;

	if (&dest[0] > &src[0])
	{
		++n;
		while (--n)
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
		return (dest);
	}
	if (&dest[0] < &src[0])
	{
		m = 0;
		while (m < n)
		{
			((unsigned char *)dest)[m] = ((unsigned char *)src)[m];
			m++;
		}
		return (dest);
	}
	return (dest);
}
