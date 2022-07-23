/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:25:53 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/24 00:17:44 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "minirt.h"
# include "vector.h"
# include "color.h"

/**
**		Ray's origin and coords correspond to ray, which is emitted by the camera.
**		Ray's color consists of 3 components: ambient, diffuse and spectular. Each
**		of component based on color of surface which has been encountered by the ray.
**		We can reach surface color using *surface pointer (collision structure).
**/

typedef struct s_collision	t_collision;
typedef struct s_vec		t_vec;
typedef struct s_color		t_color;

typedef struct s_ray
{
	t_vec			coords;
	t_vec			origin;
	t_color			color;
	t_collision		collis;
	t_vec			surf_normal;
}	t_ray;

void	emit_rays(t_minirt *rt);
void	get_ambient_component(t_minirt *rt);
// void	add_diff_component(void);
// void	add_spec_component(void);

#endif