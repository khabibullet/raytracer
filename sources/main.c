/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:10:36 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/28 21:13:55 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../libraries/libmlx/headers/mlx.h"

#include "../headers/event.h"
#include "../headers/parsing.h"
#include "../headers/test.h"
#include "../headers/utils.h"
#include "../headers/vector.h"

int	main(int argc, char **argv)
{
	t_minirt	rt;

	parse_rt(argc, argv, &rt);
	mlx_hook(rt.mlx.win, X_EVENT_KEY_PRESS, 0, &key_press, &rt);
	mlx_hook(rt.mlx.win, X_EVENT_KEY_RELEASE, 0, &key_release, &rt);
	mlx_hook(rt.mlx.win, X_EVENT_EXIT, 0, &exit_hook, &rt);
	mlx_hook(rt.mlx.win, X_EVENT_MOUSE_MOVE, 0, &mouse_hook, &rt);
	mlx_loop_hook(rt.mlx.ptr, &put_display_buff_to_window, &rt);
	// mlx_loop_hook(rt.mlx2.ptr, &fill_back_buffer, &rt);
	mlx_do_key_autorepeatoff(rt.mlx.ptr);
	mlx_loop(rt.mlx.ptr);
	return (0);
}
