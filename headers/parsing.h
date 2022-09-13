/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:58:36 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/13 17:23:37 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <fcntl.h>

# include "minirt.h"
# include "utils.h"

# include "../libraries/libft/libft.h"

# define BULB 1
# define SPHERE 0

void	alloc_objects_arrays(t_minirt *rt);
void	parse_config(char *filename, t_minirt *rt);

void	parse_rgb_light(char *line, t_color *color, float ratio);
void	parse_rgb_object(char *line, t_color *color);
void	parse_coords(char *line, t_vec *vec);

void	parse_light(char *line, t_scene *scene);
void	parse_ambient(char *line, t_scene *scene);
void	parse_camera(char *line, t_scene *scene);
void	parse_plane(char *line, t_scene *scene);
void	parse_cylinder(char *line, t_scene *scene);
void	parse_sphere(char *line, t_scene *scene, int type);
void	parse_polygon(char *line, t_scene *scene);

#endif