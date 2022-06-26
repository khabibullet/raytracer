/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 13:21:05 by enoye             #+#    #+#             */
/*   Updated: 2022/06/26 18:16:24 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ray.h"
#include "../../headers/scene.h"
#include "../../headers/vector.h"
#include <math.h>

t_vec	plane_collision(t_ray *ray, t_plane *plane)
{
	t_vec	collision;
	float	t;

	collision = subtract_vecs(ray->origin, plane->coords);
	t = -1 * dot_product(collision, plane->direction);
	t = t / dot_product(ray->coords, plane->direction);
	if (t < 0)
	{
		collision.x = NAN;
		return (collision);
	}
	collision.x = ray->origin.x + ray->coords.x * t;
	collision.y = ray->origin.y + ray->coords.y * t;
	collision.z = ray->origin.z + ray->coords.z * t;
	return (collision);
}
