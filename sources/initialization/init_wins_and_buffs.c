/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wins_and_buffs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:10:47 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/02 20:46:27 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

void	init_window_and_buffers(t_minirt *rt)
{
	rt->phong_rt.ptr = mlx_init();
	rt->fast_rt.ptr = mlx_init();
	rt->phong_rt.win = mlx_new_window(rt->phong_rt.ptr, rt->screen.width, \
												rt->screen.heigth, "miniRT");
	rt->phong_buffer.ptr = mlx_new_image(rt->phong_rt.ptr, rt->screen.width, \
															rt->screen.heigth);
	rt->phong_buffer.addr = mlx_get_data_addr(rt->phong_buffer.ptr, \
	&rt->phong_buffer.depth, &rt->phong_buffer.len, &rt->phong_buffer.end);
	rt->fast_buffer.ptr = mlx_new_image(rt->phong_buffer.ptr, rt->screen.width, \
															rt->screen.heigth);
	rt->fast_buffer.addr = mlx_get_data_addr(rt->fast_buffer.ptr, \
	&rt->fast_buffer.depth, &rt->fast_buffer.len, &rt->fast_buffer.end);
}
