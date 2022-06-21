/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pix_coords.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:36:58 by enoye             #+#    #+#             */
/*   Updated: 2022/06/21 18:18:49 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

t_pix	find_pix_coords(int i, int j, float density, float ratio)
{
	t_pix	var;

	var.x = (2 * density * j) + density - 1;
	var.y = (2 * density * i) + density - ratio;
	return (var);
}
