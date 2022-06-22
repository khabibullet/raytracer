/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:47:05 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/22 21:29:19 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

int	mouse_hook(int x2, int y2, t_rt *rt)
{
	(void)x2;
	(void)y2;
	(void)rt;
	printf("mouse\n");
	// static int	flag;
	// static int	x1;
	// static int	y1;

	// if (flag)
	// {
	// 	gen->angles[0] += ((float)(x1 - x2)) * gen->mouse_sens;
	// 	gen->angles[1] += ((float)(y1 - y2)) * gen->mouse_sens;
	// 	if (gen->angles[0] > 360)
	// 		gen->angles[0] -= 360;
	// 	else if (gen->angles[0] < -360)
	// 		gen->angles[0] += 360;
	// 	if (gen->angles[1] > 360)
	// 		gen->angles[1] -= 360;
	// 	else if (gen->angles[1] < -360)
	// 		gen->angles[1] += 360;
	// }
	// x1 = x2;
	// y1 = y2;
	// flag = 1;
	return (0);
}

int	key_press(int keycode, t_rt *rt)
{
	(void)keycode;
	(void)rt;
	mlx_loop_hook(rt->mlx, &main_loop, rt);
	// if (keycode == KEY_D)
	// 	gen->shift[0] += -gen->shift_sens;
	// else if (keycode == KEY_A)
	// 	gen->shift[0] += gen->shift_sens;
	// else if (keycode == KEY_W)
	// 	gen->shift[2] += gen->shift_sens;
	// else if (keycode == KEY_S)
	// 	gen->shift[2] += -gen->shift_sens;
	// else if (keycode == KEY_E)
	// 	gen->shift[1] += gen->shift_sens;
	// else if (keycode == KEY_Q)
	// 	gen->shift[1] += -gen->shift_sens;
	// else if (keycode == KEY_PLUS)
	// 	gen->shift_sens *= 1.2;
	// else if (keycode == KEY_MINUS)
	// 	gen->shift_sens /= 1.2;
	// else if (keycode == KEY_P)
	// 	change_proj(&gen->proj_type);
	// else if (keycode == KEY_O)
	// 	reset_cam_pos(gen);
	// else if (keycode == KEY_ESC)
	// 	exit_fdf(gen);
	// limit_shift(gen);
	return (0);
}

int	key_release(int keycode, t_rt *rt)
{
	(void)keycode;
	(void)rt;
	// if (keycode == KEY_D)
	// 	gen->shift[0] -= -gen->shift_sens;
	// else if (keycode == KEY_A)
	// 	gen->shift[0] -= gen->shift_sens;
	// else if (keycode == KEY_W)
	// 	gen->shift[2] -= gen->shift_sens;
	// else if (keycode == KEY_S)
	// 	gen->shift[2] -= -gen->shift_sens;
	// else if (keycode == KEY_E)
	// 	gen->shift[1] -= gen->shift_sens;
	// else if (keycode == KEY_Q)
	// 	gen->shift[1] -= -gen->shift_sens;
	return (0);
}

int	exit_hook(t_rt *rt)
{
	(void)rt;
	exit(EXIT_SUCCESS);
	return (0);
}

int	main_loop(t_rt *rt)
{
	char	buf[101];
	int		i;

	(void)rt;
	i = 0;
	while (i < 100)
	{
		buf[i] = '0';
		buf[i + 1] = '\n';
		write(1, &buf[0], i);
		write(1, "\n", 1);
		usleep(100000);
		i++;
	}
	return (0);
}
