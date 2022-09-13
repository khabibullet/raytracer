/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_reflect_vec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:59:18 by enoye             #+#    #+#             */
/*   Updated: 2022/09/13 11:46:44 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/vector.h"

t_vec	reflect_vec(t_vec ray, t_vec norm)
{
	float	kof;
	t_vec	reflect;

	kof = 2.0F * ((ray.x * norm.x) + (ray.y * norm.y) + (ray.z * norm.z)) / \
	((norm.x * norm.x) + (norm.y * norm.y) + (norm.z * norm.z));
	reflect.x = ray.x - kof * norm.x;
	reflect.y = ray.y - kof * norm.y;
	reflect.z = ray.z - kof * norm.z;
	return (reflect);
}
