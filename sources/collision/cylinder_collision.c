/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:11:20 by anemesis          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/04 12:48:09 by enoye            ###   ########.fr       */
=======
/*   Updated: 2022/07/05 18:44:43 by anemesis         ###   ########.fr       */
>>>>>>> 5a5ca2d40597bb37d7333e6085d42af53cb00dd0
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"
#include "../../headers/scene.h"
#include "../../headers/ray.h"
#include "../../headers/vector.h"
#include "../../headers/collision.h"

int	collide_cylinder(t_ray *ray, t_cyl *cylinder)
{
	t_vec	new_coords;
	t_vec	new_origin;
	float	d;
	float	rr;
	float	t[2];

	new_origin = subtract_vecs(ray->origin, cylinder->center);
	new_origin = matmul_mat_vec(cylinder->rot, &new_origin);
	new_coords = matmul_mat_vec(cylinder->rot, &ray->coords);
	rr = new_coords.x * new_coords.x + new_coords.y * new_coords.y;
	d = new_coords.x + new_coords.y;
	d = d * d - rr * new_origin.x * (new_origin.x + new_origin.y \
						* new_origin.y + cylinder->radius * cylinder->radius);
	if (d < 0 || (new_coords.x == 0 && new_coords.y == 0))
		return (0);
	d = sqrtf(d);
	rr = 1.0F / rr;
	t[0] = (-new_coords.x - new_coords.y + d) * rr;
	t[1] = (-new_coords.x - new_coords.y - d) * rr;
	if ((t[0] <= 0 && t[1] <= 0))
		return (0);
	new_origin = add_vecs(new_origin, vec_multiply_nbr(new_coords, t[0]));
	new_coords = add_vecs(new_origin, vec_multiply_nbr(new_coords, t[1]));
	if (fabsf(new_origin.z) > cylinder->heigth \
	&& fabsf(new_coords.z) > cylinder->heigth)
		return (0);
	if (t[0] <= 0 || (t[1] > 0 && t[0] >= t[1]))
		t[0] = t[1];
	if (t[0] - EPSILON < ray->collis.distance)
	{
		ray->collis.surface = (void *)cylinder;
		ray->collis.distance = t[0] - EPSILON;
	}
	return (1);
}
