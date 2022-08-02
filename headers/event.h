/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:58:31 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/02 20:03:48 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "minirt.h"
# include "ray.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_MOUSE_MOVE		6
# define X_EVENT_EXIT			17

void	put_buffer_to_window(t_minirt *rt, t_img *buffer);
int		phong_raytracing(t_minirt *rt);
int		fast_raytracing(t_minirt *rt);
int		key_press(int keycode, t_minirt *rt);
int		key_release(int keycode, t_minirt *rt);
int		exit_hook(t_minirt *rt);
int		mouse_hook(int x2, int y2, t_minirt *rt);

#endif