/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_raytracing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:10:44 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/08 22:17:40 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/event.h"
#include "../../headers/utils.h"

static void	brighten_rays(t_ray **rays, int heigth, int width)
{
	register int	i;
	register int	j;

	i = 0;
	while (i < heigth)
	{
		j = 0;
		while (j < width)
		{
			rays[i][j].color = mix_colors(&rays[i][j].color, \
												&(t_color){0.5F, 0.5F, 0.5F});
			++j;
		}
		++i;
	}
}

int	phong_raytracing(t_minirt *rt)
{
	if (rt->controls.motion <= 0)
		return (0);
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
	brighten_rays(rt->screen.rays, rt->screen.heigth, rt->screen.width);
	colorize_buffer(&rt->phong_buffer, rt->screen.rays, &rt->screen);
	if (rt->controls.motion <= 0)
		return (0);
	put_buffer_to_window(rt, &rt->phong_buffer);
	put_fps(rt->phong_rt.ptr, rt->phong_rt.win, &rt->screen.fps);
	update_rays(rt, rt->screen.heigth, rt->screen.width); // замена полей начала луча, направления луча и нормали к поверхности
	// add_diffuse_component(rt);
	// colorize_buffer(&rt->phong_buffer, &rt->screen.rays, &rt->screen);
	// put_buffer_to_window(rt, &rt->phong_buffer);
	// add_specular_component(rt);
	// colorize_buffer(&rt->phong_buffer, &rt->screen.rays, &rt->screen);
	// put_buffer_to_window(rt, &rt->phong_buffer);
	return (0);
}
