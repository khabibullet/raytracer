/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:10:36 by anemesis          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/04 12:04:10 by enoye            ###   ########.fr       */
=======
/*   Updated: 2022/07/02 21:49:31 by anemesis         ###   ########.fr       */
>>>>>>> fe522de18ff17d5dcbcbfcd0c11f88101cd7427c
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

#include "../libraries/libmlx/headers/mlx.h"

#include "../headers/minirt.h"
#include "../headers/event.h"
#include "../headers/parsing.h"

int	main(int argc, char **argv)
{
	t_minirt	rt;

	parse_rt(argc, argv, &rt);
	mlx_hook(rt.mlx.win, X_EVENT_KEY_PRESS, 0, &key_press, &rt);
	mlx_hook(rt.mlx.win, X_EVENT_KEY_RELEASE, 0, &key_release, &rt);
	mlx_hook(rt.mlx.win, X_EVENT_EXIT, 0, &exit_hook, &rt);
	mlx_hook(rt.mlx.win, X_EVENT_MOUSE_MOVE, 0, &mouse_hook, &rt);
	// mlx_loop_hook(rt.mlx.ptr, &put_display_buff_to_window, &rt);
	// mlx_loop_hook(rt.mlx2.ptr, &fill_back_buffer, &rt);
	mlx_do_key_autorepeatoff(rt.mlx.ptr);
	// mlx_loop(rt.mlx.ptr);
	return (0);
}
