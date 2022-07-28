/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_obj_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:39 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/28 15:25:37 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../headers/minirt.h"
#include "../../headers/scene.h"
#include "../../headers/utils.h"

void	alloc_objects_arrays(t_minirt *rt)
{
	if (rt->scene.num_of.planes != 0)
		rt->scene.planes = safe_malloc(rt->scene.num_of.planes \
												* sizeof(*rt->scene.planes));
	else
		rt->scene.planes = NULL;
	if (rt->scene.num_of.spheres != 0)
		rt->scene.spheres = safe_malloc(rt->scene.num_of.spheres \
												* sizeof(*rt->scene.spheres));
	else
		rt->scene.spheres = NULL;
	if (rt->scene.num_of.cylinders != 0)
		rt->scene.cylinders = safe_malloc(rt->scene.num_of.cylinders \
												* sizeof(*rt->scene.cylinders));
	else
		rt->scene.cylinders = NULL;
	if (rt->scene.num_of.polygons != 0)
		rt->scene.polygons = safe_malloc(rt->scene.num_of.polygons \
												* sizeof(*rt->scene.polygons));
	else
		rt->scene.polygons = NULL;
	if (rt->scene.num_of.lights != 0)
		rt->scene.lights = safe_malloc(rt->scene.num_of.lights \
												* sizeof(*rt->scene.lights));
	else
		rt->scene.lights = NULL;
}
