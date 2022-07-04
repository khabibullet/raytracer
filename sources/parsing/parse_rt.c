/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:01:10 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/04 11:55:11 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../../headers/parsing.h"
#include "../../headers/test.h"

void	parse_rt(int argc, char **argv, t_minirt *rt)
{
	t_vec	old;
	t_vec	new;

	(void)argc;
	(void)argv;
	set_test_scene(rt);
	alloc_objects_arrays(rt);
	alloc_rays_array(rt);
	alloc_tmp_collisions_array(rt);
	init_window_and_buffers(rt);
	put_test_primitives(rt);
	init_cylinders(rt);
	old = rt->scene.cylinders[0].axis;
	new = matmul_mat_vec(rt->scene.cylinders[0].rot, &old);
	new = matmul_mat_vec(rt->scene.cylinders[0].rev, &new);
	// test_collision(&rt);
	// swap_buffers(&rt);
}
