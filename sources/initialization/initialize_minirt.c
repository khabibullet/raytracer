/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_minirt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:55:00 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/13 15:55:03 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/initialization.h"

void	initialize_raytracing(t_minirt *rt)
{
	init_window_and_buffers(rt);
	init_controls(rt);
	init_pixels(rt);
	init_rays(rt);
}
