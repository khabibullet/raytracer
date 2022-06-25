/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:32:25 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/25 19:08:22 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "vector.h"
# include "color.h"

typedef struct s_sphere
{
	int		id;
	float	radius;
	t_vec	center;
	t_color	color;
}	t_sphere;

typedef struct s_cam
{
	int		id;
	int		fov;
	t_vec	coords;
	t_vec	direction;
}	t_cam;

typedef struct s_cyl
{
	int		id;
	t_vec	coords;
	t_vec	direction;
	float	fov;
}	t_cyl;

typedef struct s_plane
{
	int		id;
	t_vec	coords;
	t_vec	direction;
	float	fov;
}	t_plane;

typedef struct s_light
{
	int		id;
	t_vec	coords;
	t_vec	direction;
	float	fov;
}	t_light;

typedef struct s_cones
{
	int		id;
	t_vec	coords;
	t_vec	direction;
	float	fov;
}	t_cones;

typedef struct s_scene
{
	t_cam		cam;
	t_cam		cam_default;
	t_sphere	*spheres;
	t_cyl		*cylinders;
	t_plane		*planes;
	t_light		*lights;
}	t_scene;

#endif