/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_alloc_obj_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:39 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/17 15:13:59 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../headers/minirt.h"
#include "../../headers/scene.h"

void	alloc_objects_arrays(t_minirt *rt)
{
	if (rt->scene.num_of.planes != 0)
		rt->scene.planes = malloc(rt->scene.num_of.planes \
												* sizeof(*rt->scene.planes));
	else
		rt->scene.planes = 0;
	if (rt->scene.num_of.spheres != 0)
		rt->scene.spheres = malloc(rt->scene.num_of.spheres \
												* sizeof(*rt->scene.spheres));
	else
		rt->scene.spheres = 0;
	if (rt->scene.num_of.cylinders != 0)
		rt->scene.cylinders = malloc(rt->scene.num_of.cylinders \
												* sizeof(*rt->scene.cylinders));
	else
		rt->scene.cylinders = 0;
	if (rt->scene.num_of.polygons != 0)
		rt->scene.polygons = malloc(rt->scene.num_of.polygons \
												* sizeof(*rt->scene.polygons));
	else
		rt->scene.polygons = 0;
	if (rt->scene.num_of.lights != 0)
		rt->scene.lights = malloc(rt->scene.num_of.lights \
												* sizeof(*rt->scene.lights));
	else
		rt->scene.lights = 0;
}
