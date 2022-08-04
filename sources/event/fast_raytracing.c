/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_raytracing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:36:32 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/04 23:25:09 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/event.h"
#include "../../headers/utils.h"
#include "../../libraries/libmlx/headers/mlx.h"

int	fast_raytracing(t_minirt *rt)
{
	long int	time;

	time = current_time_ms();

	refresh_rays(rt);
	find_screen_axes(&rt->screen, &rt->scene.cam);
	move_cam(&rt->scene.cam, &rt->screen, &rt->controls);
	emit_rays(rt);
	get_nearest_collisions(rt);
	// add_ambient_component(&rt->screen, &rt->scene.ambient);
	// colorize_buffer(&rt->phong_buffer, rt->screen.rays, &rt->screen);
	// put_buffer_to_window(rt, &rt->phong_buffer);

	printf("%ld\n", current_time_ms() - time);
	return (0);
}
