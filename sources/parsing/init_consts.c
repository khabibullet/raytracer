/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_consts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:10:47 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/27 22:11:35 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "../../libraries/libmlx/headers/mlx.h"

#include "../../headers/screen.h"
#include "../../headers/minirt.h"
#include "../../headers/controls.h"
#include "../../headers/utils.h"
#include "../../headers/ray.h"
#include "../../headers/vector.h"
#include "../../headers/test.h"

void	init_consts(t_minirt *rt)
{
	rt->screen = (t_screen){1000, 1000, 0, 0};
	rt->scene.cam = (t_cam){0, {0, 0, 0}, {1, 0, 0}, 60, 0};
	rt->controls = (t_ctrl){0, 0, 0, 1};
	rt->screen.aspect_ratio = rt->screen.heigth / rt->screen.width;
	rt->screen.density = 1 / rt->screen.width;
	rt->scene.cam.focal = (float)rt->screen.width
		/ tanf((float)rt->scene.cam.fov * M_PI / 180.0);
	rt->mlx.ptr = mlx_init();
	rt->mlx2.ptr = mlx_init();
	rt->mlx.win = mlx_new_window(rt->mlx.ptr,
			rt->screen.width, rt->screen.heigth, "miniRT");
	rt->display_buff.ptr = mlx_new_image(rt->mlx.ptr,
			rt->screen.width, rt->screen.heigth);
	rt->display_buff.addr = mlx_get_data_addr(rt->display_buff.ptr,
			&rt->display_buff.depth, &rt->display_buff.len,
			&rt->display_buff.end);
	rt->back_buff.ptr = mlx_new_image(rt->mlx.ptr,
			rt->screen.width, rt->screen.heigth);
	rt->back_buff.addr = mlx_get_data_addr(rt->back_buff.ptr,
			&rt->back_buff.depth, &rt->back_buff.len, &rt->back_buff.end);
	printf("focal = %f\n", rt->scene.cam.focal);
}
