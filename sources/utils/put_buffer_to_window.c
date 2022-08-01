/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_buffer_to_window.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:15:48 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/01 23:52:47 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

void	put_buffer_to_window(t_minirt *rt, t_img *buf)
{
	mlx_put_image_to_window(rt->phong_rt.ptr, rt->phong_rt.win, buf->ptr, 0, 0);
}
