/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_raytracing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:10:44 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/04 21:18:23 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/event.h"
#include "../../headers/utils.h"
// #include "../../headers/screen.h"

int	phong_raytracing(t_minirt *rt)
{
	find_screen_axes(&rt->screen, &rt->scene.cam);
	move_cam(&rt->scene.cam, &rt->screen, &rt->controls);
	emit_rays(rt);
	get_nearest_collisions(rt);
	add_ambient_component(&rt->screen, &rt->scene.ambient);
	colorize_buffer(&rt->phong_buffer, rt->screen.rays, &rt->screen);
	put_buffer_to_window(rt, &rt->phong_buffer);
	// update_rays(rt); // замена полей начала луча, направления луча и нормали к поверхности
	// add_diffuse_component(rt);
	// colorize_buffer(&rt->phong_buffer, &rt->screen.rays, &rt->screen);
	// put_buffer_to_window(rt, &rt->phong_buffer);
	// add_specular_component(rt);
	// colorize_buffer(&rt->phong_buffer, &rt->screen.rays, &rt->screen);
	// put_buffer_to_window(rt, &rt->phong_buffer);
	return (0);
}
