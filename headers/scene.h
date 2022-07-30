/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:32:25 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/30 15:08:41 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <stdio.h>

# include "vector.h"
# include "color.h"

typedef struct s_sphere
{
	t_color	color;
	t_vec	center;
	float	radius;
}	t_sphere;

typedef struct s_cam
{
	t_vec	coords;
	t_vec	direction;
	int		fov;
	float	focal;
}	t_cam;

typedef struct s_cyl
{
	t_color	color;
	t_vec	center;
	t_vec	axis;
	float	radius;
	float	semi_heigth;
	float	rot[3][3];
	float	rev[3][3];
}	t_cyl;

typedef struct s_plane
{
	t_color	color;
	t_vec	coords;
	t_vec	normal;
}	t_plane;

typedef struct s_light
{
	t_color	color;
	t_vec	coords;
}	t_light;

typedef struct s_poly
{
	t_color	color;
	t_vec	peak1;
	t_vec	peak2;
	t_vec	peak3;
}	t_poly;

typedef struct s_num
{
	int		primitives;
	int		planes;
	int		spheres;
	int		cylinders;
	int		polygons;
	int		lights;
}	t_num;

typedef struct s_scene
{
	t_cam			cam;
	t_cam			cam_default;
	t_color			ambient;
	t_sphere		*spheres;
	t_cyl			*cylinders;
	t_plane			*planes;
	t_poly			*polygons;
	t_light			*lights;
	t_num			num_of;
}	t_scene;

#endif