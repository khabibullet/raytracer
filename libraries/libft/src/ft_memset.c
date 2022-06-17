/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:23:55 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/12 20:22:16 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *dest, int ch, size_t count)
{
	void	*ptr;

	ptr = dest;
	while (count)
	{
		*((unsigned char *)dest) = ch;
		++dest;
		--count;
	}
	return (ptr);
}
