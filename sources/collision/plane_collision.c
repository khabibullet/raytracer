/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 13:21:05 by enoye             #+#    #+#             */
/*   Updated: 2022/08/06 15:39:31 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/collision.h"
#include "../../headers/ray.h"

void	collide_plane(t_ray *ray, t_plane *plane)
{
	t_vec	collision;
	float	t;

	collision = subtract_vecs(&ray->origin, &plane->coords);
	t = -dot_product(&collision, &plane->normal) \
									/ dot_product(&ray->coords, &plane->normal);
	if (t <= 0)
		return ;
	if (t - EPSILON < ray->collis.distance)
	{
		ray->collis.surface = (void *)plane;
		ray->collis.distance = t - EPSILON;
	}
}
