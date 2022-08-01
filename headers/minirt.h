/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:05:09 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/01 23:25:16 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>

# include "scene.h"
# include "screen.h"
# include "controls.h"
# include "../libraries/libmlx/headers/mlx.h"

typedef struct s_ctrl	t_ctrl;
typedef struct s_scene	t_scene;
typedef struct s_screen	t_screen;

typedef struct s_minirt
{
	t_mlx		phong_rt;
	t_mlx		fast_rt;
	t_img		phong_buffer;
	t_img		fast_buffer;
	t_scene		scene;
	t_ctrl		controls;
	t_screen	screen;
}	t_minirt;

#endif