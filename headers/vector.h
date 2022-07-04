/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:59:29 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/02 20:51:52 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

float	dot_product(t_vec vec1, t_vec vec2);
float	vector_len(t_vec vec);
t_vec	unit_vector(t_vec vec);
t_vec	find_normal_hor(t_vec vec);
t_vec	find_normal_ver(t_vec vec);
t_vec	vec_multiply_nbr(t_vec vec, float nbr);
t_vec	add_vecs(t_vec vec1, t_vec vec2);
t_vec	subtract_vecs(t_vec vec1, t_vec vec2);
t_vec	vec_multiply_nbr(t_vec vec, float nbr);
t_vec	cross_product(t_vec vec1, t_vec vec2);
float	mix_product(t_vec vec1, t_vec vec2, t_vec vec3);
t_vec	find_reflect_vec(t_vec ray, t_vec norm);
void	matmul_mat_mat(float a[3][3], float b[3][3], float res[3][3]);
t_vec	matmul_mat_vec(float mat[3][3], t_vec *vec);

#endif