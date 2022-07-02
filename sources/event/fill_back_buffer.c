/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_back_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:10:44 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/29 16:18:24 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "../../headers/minirt.h"
#include "../../headers/test.h"
#include "../../headers/utils.h"

int	fill_back_buffer(t_minirt *rt)
{
	add_amb_component(rt);
	// choose_nearest_collision(); // еще нужно количество пересечений

	// swap_buffers(rt);
	// usleep(10000);
	return (0);
}
