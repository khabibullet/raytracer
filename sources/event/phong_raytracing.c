/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_raytracing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:10:44 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/14 16:49:13 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/event.h"
#include "../../headers/utils.h"
#include "unistd.h"

int	phong_raytracing(t_minirt *rt)
{
	mlx_clear_window(rt->phong_rt.ptr, rt->phong_rt.win);
	refresh_rays(rt->screen.rays, rt->screen.heigth, rt->screen.width);
	move_cam(&rt->scene.cam, &rt->screen, &rt->controls);
	rotate_cam_ver(&rt->scene.cam, &rt->controls);
	rotate_cam_hor(&rt->scene.cam, &rt->controls);
	find_screen_axes(&rt->screen, &rt->scene.cam.direction);
	emit_rays(&rt->screen, &rt->scene.cam, rt->screen.heigth, rt->screen.width);
	get_first_collisions(rt->screen.rays, &rt->scene, \
										rt->screen.heigth, rt->screen.width);
	add_ambient_component(rt->screen.rays, &rt->scene.ambient, \
										rt->screen.heigth, rt->screen.width);
	if (rt->controls.motion <= 0)
	{
		revert_rays(rt->screen.rays, rt->screen.heigth, rt->screen.width);
		add_diffuse_component(rt->screen.rays, rt->screen.heigth, \
												rt->screen.width, &rt->scene);
		add_specular_component(rt->screen.rays, rt->screen.heigth, \
												rt->screen.width, &rt->scene);
	}
	colorize_buffer(&rt->buffer, rt->screen.rays, &rt->screen);
	put_buffer_to_window(rt, &rt->buffer);
	put_fps(rt->phong_rt.ptr, rt->phong_rt.win, &rt->screen.fps);
	return (0);
}
