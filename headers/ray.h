/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:25:53 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/15 12:31:07 by anemesis         ###   ########.fr       */
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
	t_vec			beam;
	t_color			color;
	t_collision		collis;
}	t_ray;

typedef struct s_minirt	t_minirt;
typedef struct s_screen	t_screen;
typedef struct s_img	t_img;

void	emit_rays(t_screen *screen, t_cam *cam, int heigth, int width);
void	add_ambient_component(t_ray **rays, t_color	*ambient, int heigth, \
																int width);
void	add_diffuse_component(t_ray **rays, int heigth, int width, t_scene *sc);
void	add_specular_component(t_ray **rays, int heigth, int width, \
																t_scene *sc);
void	revert_rays(t_ray **rays, int heigth, int width);
void	colorize_buffer(t_img *buffer, t_ray **rays, t_screen *screen);
void	refresh_rays(t_ray **rays, int heigth, int width);
t_color	current_ray_diffuse(t_ray *ray, t_scene *scene);
void	check_if_shaded(t_ray *ray, t_scene *scene);
t_color	current_ray_specular(t_ray *ray, t_scene *scene);
void	brighten_ambient(t_ray **rays, int heigth, int width);

#endif