/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_tmp_collisions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:09:02 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/29 16:14:59 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

void	alloc_tmp_collisions_array(t_minirt *rt)
{
	rt->scene.tmp_collisions = malloc(sizeof(*rt->scene.tmp_collisions) * \
												rt->scene.num_of.primitives);
}
