/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:10:36 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/26 16:44:13 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libraries/libmlx/headers/mlx.h"

#include "../headers/event.h"
#include "../headers/parsing.h"
#include "../headers/collision.h"

#include <stdio.h>

int	main(void)
{
	// t_minirt	rt;

	// init_consts(&rt);
	// mlx_hook(rt.mlx.win, X_EVENT_KEY_PRESS, 0, &key_press, &rt);
	// mlx_hook(rt.mlx.win, X_EVENT_KEY_RELEASE, 0, &key_release, &rt);
	// mlx_hook(rt.mlx.win, X_EVENT_EXIT, 0, &exit_hook, &rt);
	// mlx_hook(rt.mlx.win, X_EVENT_MOUSE_MOVE, 0, &mouse_hook, &rt);
	// mlx_loop_hook(rt.mlx.ptr, &fill_back_buffer, &rt);
	// mlx_loop_hook(rt.mlx.ptr, &put_display_buff_to_window, &rt);
	// mlx_do_key_autorepeatoff(rt.mlx.ptr);
	// mlx_loop(rt.mlx.ptr);
	t_ray	ray;
	t_plane	plane;
	t_vec	collision;

	ray.coords.x = 1;
	ray.coords.y = 1;
	ray.coords.z = 2;

	ray.origin.x = 1;
	ray.origin.y = 1;
	ray.origin.z = 2;

	plane.direction.x = 1;
	plane.direction.y = 1;
	plane.direction.z = 3;

	plane.coords.x = 1;
	plane.coords.y = 1;
	plane.coords.z = 3;
	collision = plane_collision(&ray, &plane);
	printf("coll:%f\n", collision.z);
	return (0);
}
