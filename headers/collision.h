/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:16:36 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/13 17:56:50 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H
# define MD_FULL 1
# define MD_PART 0
# define EPSILON 0.001F
# define ORIGIN 0
# define COORDS 1
# define NOT_NULL ((void *)1)
# define FULL 1
# define FAST 0

# include <stdio.h>

# include "scene.h"

typedef struct s_collision
{
	float	distance;
	void	*surface;
	t_vec	surf_normal;
	int		surf_type;
}	t_collision;

typedef struct s_ray	t_ray;
typedef struct s_minirt	t_minirt;

int		collide_sphere(t_ray *ray, t_sphere *sphere, int mode, int i, int j);
int		collide_cylinder(t_ray *ray, t_cyl *cylinder, int mode);
int		collide_plane(t_ray *ray, t_plane *plane, int mode);
int		collide_poly(t_ray *ray, t_poly *poly, int mode);
void	get_first_collisions(t_ray **ray, t_scene *sc, int heigth, int width);
int		current_ray_nearest_collision(t_ray *ray, t_scene *scene, int modem, int i, int j);

#endif