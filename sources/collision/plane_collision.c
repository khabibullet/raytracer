/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 13:21:05 by enoye             #+#    #+#             */
/*   Updated: 2022/08/09 16:25:14 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/collision.h"
#include "../../headers/ray.h"

int	collide_plane(t_ray *ray, t_plane *plane, int mode)
{
	t_vec	collision;
	float	t;

	collision = subtract_vecs(&ray->origin, &plane->coords);
	t = -dot_product(&collision, &plane->normal) \
									/ dot_product(&ray->coords, &plane->normal);
	if (t <= 0 || t - EPSILON >= ray->collis.distance)
		return (0);
	if (mode == FAST)
		return (1);
	ray->collis.surface = (void *)plane;
	ray->collis.distance = t - EPSILON;
	ray->collis.surf_normal = plane->coords;
	return (1);
}
