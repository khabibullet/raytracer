/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_raytracing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:36:32 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/09 22:55:21 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/event.h"
#include "../../headers/utils.h"
#include "../../libraries/libmlx/headers/mlx.h"

int	fast_raytracing(t_minirt *rt)
{
	if (rt->controls.motion <= 0)
		return (0);
	mlx_clear_window(rt->phong_rt.ptr, rt->phong_rt.win);
	refresh_rays(rt->screen.rays, rt->screen.heigth, rt->screen.width);
	move_cam(&rt->scene.cam, &rt->screen, &rt->controls);
	rotate_cam_ver(&rt->scene.cam, &rt->controls);
	rotate_cam_hor(&rt->scene.cam, &rt->controls);
	find_screen_axes(&rt->screen, &rt->scene.cam.direction);
	emit_rays(&rt->screen, &rt->scene.cam, rt->screen.heigth, rt->screen.width);
	get_nearest_collisions(rt->screen.rays, &rt->scene, \
										rt->screen.heigth, rt->screen.width);
	add_ambient_component(rt->screen.rays, &rt->scene.ambient, \
										rt->screen.heigth, rt->screen.width);
	put_light_point(rt->screen.rays, &rt->scene, \
										rt->screen.heigth, rt->screen.width);
	colorize_buffer(&rt->fast_buffer, rt->screen.rays, &rt->screen);
	if (rt->controls.motion <= 0)
		return (0);
	put_buffer_to_window(rt, &rt->fast_buffer);
	put_fps(rt->phong_rt.ptr, rt->phong_rt.win, &rt->screen.fps);
	return (0);
}
