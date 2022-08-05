/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_to_pix_vec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:23:56 by enoye             #+#    #+#             */
/*   Updated: 2022/08/05 13:56:54 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/screen.h"

t_vec	cam_to_pix_vec(t_cam *cam, t_pix *pix_coords, t_screen *screen)
{
	t_vec	hor_axis;
	t_vec	ver_axis;
	t_vec	sum;

	hor_axis = vec_multiply_nbr(&screen->hor_axis, pix_coords->x);
	ver_axis = vec_multiply_nbr(&screen->ver_axis, pix_coords->y);
	sum = add_vecs(vec_multiply_nbr(&cam->direction, cam->focal), hor_axis);
	sum = add_vecs(sum, ver_axis);
	return (sum);
}
