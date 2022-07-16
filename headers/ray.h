/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:25:53 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/04 23:28:26 by anemesis         ###   ########.fr       */
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
**		of component based on color of surface which has been collided with the ray.
**		We can reach surface color using *surface pointer.
**/

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
update_rays
// void	add_diff_component(void);
// void	add_spec_component(void);

#endif