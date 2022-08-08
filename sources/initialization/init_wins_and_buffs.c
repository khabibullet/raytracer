/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wins_and_buffs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:10:47 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/08 19:07:09 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"
#include "../../headers/utils.h"

void	init_window_and_buffers(t_minirt *rt)
{
	rt->phong_rt.ptr = mlx_init();
	if (rt->phong_rt.ptr == NULL)
		exit_error("Cannot initialize mlx");
	rt->fast_rt.ptr = mlx_init();
	if (rt->fast_rt.ptr == NULL)
		exit_error("Cannot initialize mlx");
	rt->phong_rt.win = mlx_new_window(rt->phong_rt.ptr, rt->screen.width, \
												rt->screen.heigth, "miniRT");
	if (rt->phong_rt.win == NULL)
		exit_error("Cannot initialize window");
	rt->phong_buffer.ptr = mlx_new_image(rt->phong_rt.ptr, rt->screen.width, \
															rt->screen.heigth);
	if (rt->phong_buffer.ptr == NULL)
		exit_error("Cannot initialize image");
	rt->phong_buffer.addr = mlx_get_data_addr(rt->phong_buffer.ptr, \
	&rt->phong_buffer.depth, &rt->phong_buffer.len, &rt->phong_buffer.end);
	rt->fast_buffer.ptr = mlx_new_image(rt->phong_buffer.ptr, rt->screen.width, \
															rt->screen.heigth);
	if (rt->fast_buffer.ptr == NULL)
		exit_error("Cannot initialize image");
	rt->fast_buffer.addr = mlx_get_data_addr(rt->fast_buffer.ptr, \
	&rt->fast_buffer.depth, &rt->fast_buffer.len, &rt->fast_buffer.end);
}
