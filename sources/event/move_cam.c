/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:44:19 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/04 21:51:35 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/event.h"
#include "../../headers/vector.h"

void	move_cam(t_cam *cam, t_screen *screen, t_ctrl *controls)
{
	cam->coords = add_vecs(cam->coords, vec_multiply_nbr(\
				screen->hor_axis, controls->hor_shift * controls->velocity));
	cam->coords = add_vecs(cam->coords, vec_multiply_nbr(\
				screen->ver_axis, controls->ver_shift * controls->velocity));
	cam->coords = add_vecs(cam->coords, vec_multiply_nbr(\
				cam->direction, controls->zoom * controls->velocity));
	return ;
}
