/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:00:50 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/02 21:43:54 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../../headers/scene.h"
#include "../../headers/minirt.h"

void	set_test_scene(t_minirt *rt)
{
	rt->screen = (t_screen){1000, 1000, 0, 0, NULL};
	rt->controls = (t_ctrl){0, 0, 0, 1};
	rt->scene.cam = (t_cam){0, {0, 0, 0}, {1, 0, 0}, 60, 0};
	rt->scene.num_of = (t_num){8, 2, 2, 1, 2, 1};
	rt->scene.ambient = (t_amb){{255, 255, 255}, 0.5};
}
