/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_consts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:10:47 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/25 19:27:17 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libraries/libmlx/headers/mlx.h"

#include "../../headers/screen.h"
#include "../../headers/minirt.h"
#include "../../headers/controls.h"

void	fill_buffer_color(t_img *buff, int w, int h, unsigned int color)
{
	int		x;
	int		y;
	char	*dst;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			dst = buff->addr + (y * buff->len + x * (buff->depth / 8));
			*(unsigned int *)dst = color;
			x++;
		}
		y++;
	}
}

void	init_consts(t_minirt *rt)
{
	unsigned int	color;

	rt->controls = (t_ctrl){0, 0, 0, 1};
	rt->screen = (t_screen){1000, 1000, 0, 0};
	rt->screen.aspect_ratio = rt->screen.heigth / rt->screen.width;
	rt->screen.aspect_ratio = 1 / rt->screen.width;
	rt->mlx.ptr = mlx_init();
	rt->mlx.win = mlx_new_window(rt->mlx.ptr,
			rt->screen.width, rt->screen.heigth, "miniRT");
	rt->display_buff.ptr = mlx_new_image(rt->mlx.ptr,
			rt->screen.width, rt->screen.heigth);
	rt->display_buff.addr = mlx_get_data_addr(rt->display_buff.ptr,
			&rt->display_buff.depth, &rt->display_buff.len,
			&rt->display_buff.end);
	rt->back_buff.ptr = mlx_new_image(rt->mlx.ptr,
			rt->screen.width, rt->screen.heigth);
	rt->back_buff.addr = mlx_get_data_addr(rt->back_buff.ptr,
			&rt->back_buff.depth, &rt->back_buff.len, &rt->back_buff.end);
	color = 0x00FFFFFF;
	fill_buffer_color(&rt->back_buff,
		rt->screen.width, rt->screen.heigth, color);
}
