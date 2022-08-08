/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:10:36 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/08 21:14:24 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/validation.h"
#include "../headers/parsing.h"
#include "../headers/initialization.h"
#include "../headers/event.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_minirt		rt;

	validate_config(argc, argv[1], &rt.scene.num_of);
	parse_config(argv[1], &rt);
	set_screen_properties(&rt.screen, 700, 700);
	initialize_raytracing(&rt);
	mlx_hook(rt.phong_rt.win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, &rt);
	mlx_hook(rt.phong_rt.win, X_EVENT_KEY_RELEASE, 1L << 1, &key_release, &rt);
	mlx_hook(rt.phong_rt.win, X_EVENT_EXIT, 1L << 17, &exit_free, &rt);
	mlx_hook(rt.phong_rt.win, X_EVENT_MOUSE_MOVE, 1L << 6, &mouse_hook, &rt);
	mlx_hook(rt.phong_rt.win, X_EVENT_MOUSE_PRESS, 1L << 2, &mouse_press, &rt);
	mlx_hook(rt.phong_rt.win, X_EVENT_MOUSE_RELEASE, 1L << 3, \
														&mouse_release, &rt);
	mlx_loop_hook(rt.phong_rt.ptr, &phong_raytracing, &rt);
	mlx_loop_hook(rt.fast_rt.ptr, &fast_raytracing, &rt);
	mlx_do_key_autorepeatoff(rt.phong_rt.ptr);
	mlx_loop(rt.phong_rt.ptr);
	mlx_loop(rt.fast_rt.ptr);
	return (0);
}
