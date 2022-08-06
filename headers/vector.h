/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:59:29 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/06 22:24:38 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include <stdio.h>

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

typedef struct s_cam		t_cam;
typedef struct s_ctrl		t_ctrl;

float	dot_product(t_vec *vec1, t_vec *vec2);
float	vector_len(t_vec *vec);
t_vec	unit_vector(t_vec *vec);
t_vec	find_normal_hor(t_vec *vec);
t_vec	find_normal_ver(t_vec *vec);
t_vec	add_vecs(t_vec *vec1, t_vec *vec2);
t_vec	subtract_vecs(t_vec *vec1, t_vec *vec2);
t_vec	vec_multiply_nbr(t_vec *vec, float nbr);
t_vec	cross_product(t_vec *vec1, t_vec *vec2);
float	mix_product(t_vec *vec1, t_vec *vec2, t_vec *vec3);
t_vec	find_reflect_vec(t_vec ray, t_vec norm);
void	matmul_mat_mat(float a[3][3], float b[3][3], float res[3][3]);
t_vec	matmul_mat_vec(float mat[3][3], t_vec *vec);
t_vec	hadam_product(t_vec v1, t_vec v2);
void	get_rot_matrix(float rot[3][3], t_vec v);
void	get_rev_matrix(float rev[3][3], float rot[3][3]);
void	rotate_cam(t_cam *cam, t_ctrl *controls);

#endif