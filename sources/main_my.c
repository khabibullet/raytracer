/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_my.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:03:07 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/22 16:21:13 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	t_rt	rt;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 100, 100, "test");
	rt = (t_rt){0, 0, mlx, win};
	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, &rt);
	mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_release, &rt);
	mlx_hook(win, X_EVENT_EXIT, 0, &exit_hook, &rt);
	mlx_hook(win, X_EVENT_MOUSE_MOVE, 0, &mouse_hook, &rt);
	mlx_loop_hook(mlx, &main_loop, &rt);
	mlx_do_key_autorepeatoff(mlx);
	mlx_loop(mlx);
	return (0);
}

