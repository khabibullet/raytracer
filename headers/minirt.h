/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:05:09 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/02 20:47:13 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "screen.h"
# include "scene.h"
# include "controls.h"

typedef struct s_minirt
{
	t_mlx		mlx;
	t_mlx		mlx2;
	t_img		display_buff;
	t_img		back_buff;
	t_scene		scene;
	t_ctrl		controls;
	t_screen	screen;
}	t_minirt;

#endif