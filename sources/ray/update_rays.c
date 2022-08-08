/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:27:25 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/08 17:53:23 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ray.h"
#include "../../headers/minirt.h"

void	update_rays(t_minirt *rt, int heigth, int width)
{
	int		i;
	int		j;
	t_ray	*ray;

	i = 0;
	while (i < heigth)
	{
		j = 0;
		while (j < width)
		{
			ray = &rt->screen.rays[i][j];
			ray->coords = vec_multiply_nbr(&ray->coords, \
												ray->collis.distance - EPSILON);
			ray->origin = add_vecs(&ray->origin, &ray->coords);
			ray->coords = vec_multiply_nbr(&ray->coords, -1.0F);
			// get_surf_normal();
			j++;
		}
		i++;
	}
}
