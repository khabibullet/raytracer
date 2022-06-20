/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:23:45 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/19 16:08:02 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	m;

	if (dest > src)
	{
		++n;
		while (--n)
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
		return (dest);
	}
	else if (dest < src)
	{
		m = 0;
		while (m < n)
		{
			((unsigned char *)dest)[m] = ((unsigned char *)src)[m];
			m++;
		}
		return (dest);
	}
	else
		return (dest);
}
