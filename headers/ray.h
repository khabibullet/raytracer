/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:25:53 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/28 15:26:29 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <stdio.h>
# include <math.h>

# include "collision.h"

/**
**		Ray's origin and coords correspond to ray, which is emitted by the camera.
**		Ray's color consists of 3 components: ambient, diffuse and spectular. Each
**		of component based on color of surface which has been encountered by the ray.
**		We can reach surface color using *surface pointer (collision structure).
**/

typedef struct s_ray
{
	t_vec			coords;
	t_vec			origin;
	t_color			color;
	t_collision		collis;
	t_vec			surf_normal;
}	t_ray;

typedef struct s_minirt	t_minirt;

void	emit_rays(t_minirt *rt);
void	get_ambient_component(t_minirt *rt);
void	get_diffuse_component(t_minirt *rt);
void	get_specular_component(t_minirt *rt);
void	update_rays(t_minirt *rt);
void	put_colors_to_back_buff(t_minirt *rt);

#endif