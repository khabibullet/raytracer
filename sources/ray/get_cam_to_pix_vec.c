/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cam_to_pix_vec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:23:56 by enoye             #+#    #+#             */
/*   Updated: 2022/06/21 21:05:15 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

t_vec	get_cam_to_pix_vec(t_vec cam_dir, float focal, t_pix pix_coords)
{
	t_vec	normal_hor;
	t_vec	normal_ver;
	t_vec	sum;

	cam_dir = vec_multiply_nbr(cam_dir, focal);
	normal_hor = find_normal_hor(cam_dir);
	normal_ver = find_normal_ver(cam_dir);
	normal_hor = unit_vector(normal_hor);
	normal_ver = unit_vector(normal_ver);
	normal_hor = vec_multiply_nbr(normal_hor, pix_coords.x);
	normal_ver = vec_multiply_nbr(normal_ver, pix_coords.y);
	sum = add_vecs(cam_dir, normal_hor);
	sum = add_vecs(sum, normal_ver);
	return (sum);
}
