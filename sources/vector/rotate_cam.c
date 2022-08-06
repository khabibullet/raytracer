/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:01:59 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/06 23:29:52 by anemesis         ###   ########.fr       */
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
	return (new);
}

void	rotate_cam(t_cam *cam, t_ctrl *controls)
{
	float	rot[3][3];
	float	rev[3][3];
	t_vec	tmp;
	t_vec	ax;

	if (controls->mouse_press == 0)
		return ;
	tmp = cam->direction;
	tmp = rotate_around_z(&tmp, controls->d_fi);
	tmp = unit_vector(&tmp);
	ax = find_normal_hor(&tmp);
	ax = unit_vector(&ax);
	get_rot_matrix(rot, ax);
	get_rev_matrix(rev, rot);
	tmp = matmul_mat_vec(rot, &tmp);
	tmp = unit_vector(&tmp);
	tmp = rotate_around_z(&tmp, controls->d_teta);
	tmp = unit_vector(&tmp);
	tmp = matmul_mat_vec(rev, &tmp);
	tmp = unit_vector(&tmp);
	cam->direction = tmp;
	controls->d_fi = 0;
	controls->d_teta = 0;
}
