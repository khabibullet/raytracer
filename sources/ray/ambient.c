/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:14:42 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/06 15:48:41 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"
#include "../../headers/ray.h"
#include "../../headers/collision.h"

void	add_ambient_component(t_ray **rays, t_color	*ambient, int heigth, \
																	int width)
{
	register int	i;
	register int	j;

	i = 0;
	while (i < heigth)
	{
		j = 0;
		while (j < width)
		{
			if (rays[i][j].collis.surface != NULL)
				rays[i][j].color = mix_colors(\
					(t_color *)(rays[i][j].collis.surface), ambient);
			++j;
		}
		++i;
	}
}
