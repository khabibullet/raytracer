/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:05:09 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/04 12:34:52 by enoye            ###   ########.fr       */
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