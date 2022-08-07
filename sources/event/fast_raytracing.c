/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_raytracing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:36:32 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/07 17:57:44 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/event.h"
#include "../../headers/utils.h"
#include "../../libraries/libmlx/headers/mlx.h"

// extern int	g_count;
// extern int	g_sum;

int	fast_raytracing(t_minirt *rt)
{
	// long int	time;

	// time = current_time_ms();

	refresh_rays(rt->screen.rays, rt->screen.heigth, rt->screen.width);
	move_cam(&rt->scene.cam, &rt->screen, &rt->controls);
	print_vec(rt->scene.cam.direction);
	printf("\n");
	rotate_cam_ver(&rt->scene.cam, &rt->controls);
	print_vec(rt->scene.cam.direction);
	rotate_cam_hor(&rt->scene.cam, &rt->controls);
	print_vec(rt->scene.cam.direction);
	printf("\n");
	rotate_cam_ver(&rt->scene.cam, &rt->controls);
	print_vec(rt->scene.cam.direction);
	rotate_cam_hor(&rt->scene.cam, &rt->controls);
	print_vec(rt->scene.cam.direction);
	printf("\n");
	find_screen_axes(&rt->screen, &rt->scene.cam.direction);
	emit_rays(&rt->screen, &rt->scene.cam, rt->screen.heigth, rt->screen.width);
	get_nearest_collisions(rt->screen.rays, &rt->scene, \
										rt->screen.heigth, rt->screen.width);
	add_ambient_component(rt->screen.rays, &rt->scene.ambient, \
										rt->screen.heigth, rt->screen.width);
	colorize_buffer(&rt->phong_buffer, rt->screen.rays, &rt->screen);
	put_buffer_to_window(rt, &rt->phong_buffer);

	// g_count++;
	// g_sum += (current_time_ms() - time);
	// if (g_count > 20)
	// {
	// 	printf("average time: %d\n", g_sum / g_count);
	// 	exit(0);
	// }
	return (0);
}
