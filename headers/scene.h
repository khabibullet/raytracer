/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:32:25 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/02 18:20:20 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "vector.h"
# include "color.h"
# include "ray.h"

typedef struct s_sphere
{
	int		id;
	t_color	color;
	t_vec	center;
	float	radius;
}	t_sphere;

typedef struct s_cam
{
	int		id;
	t_vec	coords;
	t_vec	direction;
	int		fov;
	float	focal;
}	t_cam;

typedef struct s_cyl
{
	int		id;
	t_color	color;
	t_vec	center;
	t_vec	axis;
	float	diametr;
	float	heigth;
}	t_cyl;

typedef struct s_plane
{
	int		id;
	t_color	color;
	t_vec	coords;
	t_vec	normal;
}	t_plane;

typedef struct s_light
{
	int		id;
	t_color	color;
	t_vec	coords;
}	t_light;

typedef struct s_amb
{
	t_vec	color;
	float	ratio;
}	t_amb;

typedef struct s_poly
{
	int		id;
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
	t_cam		cam;
	t_cam		cam_default;
	t_amb		ambient;
	t_sphere	*spheres;
	t_cyl		*cylinders;
	t_plane		*planes;
	t_poly		*polygons;
	t_light		*lights;
	t_num		num_of;
	t_ray		*tmp_collisions;
}	t_scene;

#endif