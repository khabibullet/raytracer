/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_raytracing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:36:32 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/05 17:59:42 by anemesis         ###   ########.fr       */
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

	refresh_rays(rt);
	find_screen_axes(&rt->screen, &rt->scene.cam);
	move_cam(&rt->scene.cam, &rt->screen, &rt->controls);
	emit_rays(rt);
	get_nearest_collisions(rt);
	add_ambient_component(&rt->screen, &rt->scene.ambient);
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
