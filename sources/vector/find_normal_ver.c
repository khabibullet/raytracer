/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_normal_ver.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:30:10 by enoye             #+#    #+#             */
/*   Updated: 2022/06/21 16:38:20 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

t_vec	find_normal_ver(t_vec vec)
{
	t_vec	var;

	var.x = vec.x * vec.z;
	var.y = vec.y * vec.z;
	var.z = -(vec.x * vec.x + vec.y * vec.y);
	return (var);
}