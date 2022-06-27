/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:16:36 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/27 19:57:15 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H

# include "scene.h"
# include "ray.h"
# include "vector.h"

t_vec	collide_sphere(t_ray *ray, t_sphere *sphere);
t_vec	plane_collision(t_ray *ray, t_plane *plane);
t_vec	collide_poly(t_ray *ray, t_poly *poly);

#endif