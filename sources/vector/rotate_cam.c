/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:01:59 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/07 16:57:48 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"
#include "../../headers/utils.h"

static t_vec	rotate_around_z(t_vec *old, float sin)
{
	t_vec	new;
	float	cos;

	cos = cosf(sin);
	sin = sinf(sin);
	new.x = cos * old->x - sin * old->y;
	new.y = sin * old->x + cos * old->y;
	new.z = old->z;
	return (unit_vector(new));
}

void	rotate_cam_ver(t_cam *cam, t_ctrl *controls)
{
	float	rot[3][3];
	float	rev[3][3];
	t_vec	tmp;
	t_vec	ax;

	if (controls->mouse_press == 0)
		return ;
	tmp = cam->direction;
	ax = find_normal_hor(&tmp);
	get_rot_matrix(rot, ax);
	get_rev_matrix(rev, rot);
	tmp = unit_vector(matmul_mat_vec(rot, &tmp));
	tmp = rotate_around_z(&tmp, controls->d_teta);
	tmp = unit_vector(matmul_mat_vec(rev, &tmp));
	cam->direction = tmp;
}

void	rotate_cam_hor(t_cam *cam, t_ctrl *controls)
{
	if (controls->mouse_press == 0)
		return ;
	cam->direction = rotate_around_z(&cam->direction, controls->d_fi);
}
