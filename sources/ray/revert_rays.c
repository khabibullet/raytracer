/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revert_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:27:25 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/09 18:50:36 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ray.h"

void	revert_rays(t_ray **rays, int heigth, int width)
{
	register int	i;
	register int	j;

	i = 0;
	while (i < heigth)
	{
		j = 0;
		while (j < width)
		{
			rays[i][j].coords = vec_multiply_nbr(&rays[i][j].coords, \
											rays[i][j].collis.distance);
			rays[i][j].origin = add_vecs(&rays[i][j].origin, \
														&rays[i][j].coords);
			rays[i][j].coords = vec_multiply_nbr(&rays[i][j].coords, -1.0F);
			rays[i][j].collis.surf_normal = unit_vector(\
											rays[i][j].collis.surf_normal);
			++j;
		}
		++i;
	}
}
