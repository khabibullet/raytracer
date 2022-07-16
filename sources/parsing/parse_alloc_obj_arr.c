/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_alloc_obj_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:39 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/12 13:26:14 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../headers/minirt.h"

void	alloc_objects_arrays(t_minirt *rt)
{
	if (rt->scene.num_of.planes != 0)
		rt->scene.plane = malloc(rt->scene.num_of.planes * sizeof(t_plane));
	else
		rt->scene.plane = 0;
	if (rt->scene.num_of.spheres != 0)
		rt->scene.sphere = malloc(rt->scene.num_of.spheres * sizeof(t_sphere));
	else
		rt->scene.sphere = 0;
	if (rt->scene.num_of.cylinders != 0)
		rt->scene.cylinders = malloc(rt->scene.num_of.cylinders * sizeof(t_cyl));
	else
		rt->scene.cylinders = 0;
	if (rt->scene.num_of.polygones != 0)
		rt->scene.polygones = malloc(rt->scene.num_of.polygones * sizeof(t_poly));
	else
		rt->scene.polygones = 0;
	if (rt->scene.num_of.lights != 0)
		rt->scene.lights = malloc(rt->scene.num_of.lights * sizeof(t_light));
	else
		rt->scene.lights = 0;
}
