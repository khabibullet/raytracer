/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_tmp_collisions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:09:02 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/02 21:05:49 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../headers/minirt.h"

void	alloc_tmp_collisions_array(t_minirt *rt)
{
	rt->scene.tmp_collisions = malloc(sizeof(*rt->scene.tmp_collisions) * \
												rt->scene.num_of.primitives);
}
