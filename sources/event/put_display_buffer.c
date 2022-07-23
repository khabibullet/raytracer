/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_display_buffer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:36:32 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/23 22:22:35 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/event.h"

int	put_display_buff_to_window(t_minirt *rt)
{
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win,
		rt->display_buff.ptr, 0, 0);
	return (0);
}
