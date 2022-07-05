/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:16:36 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/04 23:29:24 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H
# define MD_FULL 1
# define MD_PART 0
# define EPSILON 0.0001F

# include "minirt.h"
# include "scene.h"
# include "ray.h"
# include "vector.h"

typedef struct s_collision
{
	float	distance;
	void	*surface;
}	t_collision;

int		collide_sphere(t_ray *ray, t_sphere *sphere, int mode);
int		collide_plane(t_ray *ray, t_plane *plane, t_collision *collision);
int		collide_poly(t_ray *ray, t_poly *poly, t_collision *collision);
void	get_nearest_collisions(t_minirt *rt);

#endif