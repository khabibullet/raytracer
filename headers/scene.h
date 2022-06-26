/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:32:25 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/26 18:56:43 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "vector.h"
# include "color.h"

typedef struct s_sphere
{
	int		id;
	t_vec	center;
	t_vec	color;
	float	radius;
}	t_sphere;

typedef struct s_cam
{
	int		id;
	t_vec	coords;
	t_vec	direction;
	int		fov;
}	t_cam;

typedef struct s_cyl
{
	int		id;
	t_vec	center;
	t_vec	color;
	t_vec	axis;
	float	diametr;
	float	heigth;
}	t_cyl;

typedef struct s_plane
{
	int		id;
	t_vec	coords;
	t_vec	color;
	t_vec	normal;
}	t_plane;

typedef struct s_light
{
	int		id;
	t_vec	coords;
	t_color	color;
}	t_light;

typedef struct s_amb
{
	t_color	color;
	float	ratio;
}	t_amb;

typedef struct s_poly
{
	int		id;
	t_vec	peak1;
	t_vec	peak2;
	t_vec	peak3;
	t_vec	color;
}	t_poly;

typedef struct s_scene
{
	t_cam		cam;
	t_cam		cam_default;
	t_amb		ambient;
	t_sphere	*spheres;
	t_cyl		*cylinders;
	t_plane		*planes;
	t_poly		*polygons;
	t_light		*lights;
}	t_scene;

#endif