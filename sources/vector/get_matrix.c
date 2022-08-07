/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:12:19 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/07 22:39:38 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/vector.h"

void	get_rot_matrix(float rot[3][3], t_vec v)
{
	float	dxy;

	rot[2][0] = v.x;
	rot[2][1] = v.y;
	rot[2][2] = v.z;
	dxy = sqrtf(1.0F - v.z * v.z);
	rot[1][2] = dxy;
	dxy = 1.0F / dxy;
	v.x *= dxy;
	v.y *= dxy;
	rot[0][0] = v.y;
	rot[0][1] = -v.z;
	rot[0][2] = 0.0F;
	rot[1][0] = v.x * v.z;
	rot[1][1] = v.y * v.z;
}

void	get_rev_matrix(float rev[3][3], float rot[3][3])
{
	rev[0][0] = rot[0][0];
	rev[1][1] = rot[1][1];
	rev[2][2] = rot[2][2];
	rev[0][1] = rot[1][0];
	rev[1][0] = rot[0][1];
	rev[1][2] = rot[2][1];
	rev[2][1] = rot[1][2];
	rev[0][2] = rot[2][0];
	rev[2][0] = rot[0][2];
}
