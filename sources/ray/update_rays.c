/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:27:25 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/08 19:28:41 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ray.h"

void	update_rays(t_ray **rays, int heigth, int width)
{
	int		i;
	int		j;

	i = 0;
	while (i < heigth)
	{
		j = 0;
		while (j < width)
		{
			rays[i][j].coords = vec_multiply_nbr(&rays[i][j].coords, \
										rays[i][j].collis.distance - EPSILON);
			rays[i][j].origin = add_vecs(&rays[i][j].origin, \
														&rays[i][j].coords);
			rays[i][j].coords = vec_multiply_nbr(&rays[i][j].coords, -1.0F);
			// get_surf_normal();
			j++;
		}
		i++;
	}
}
