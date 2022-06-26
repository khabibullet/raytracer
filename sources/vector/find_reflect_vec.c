/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_reflect_vec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:59:18 by enoye             #+#    #+#             */
/*   Updated: 2022/06/26 11:53:43 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/vector.h"

t_vec	find_reflect_vec(t_vec ray, t_vec norm)
{
	float	kof;
	t_vec	reflect;

	kof = 2 * ((ray.x * norm.x) + (ray.y * norm.y) + (ray.z * norm.z)) / \
	((norm.x * norm.x) + (norm.y * norm.y) + (norm.z * norm.z));
	reflect.x = ray.x - kof * norm.x;
	reflect.y = ray.y - kof * norm.y;
	reflect.z = ray.z - kof * norm.z;
	return (reflect);
}
