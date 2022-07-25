/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:58:36 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/24 21:27:30 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>

# include "minirt.h"

typedef struct s_id
{
	int	sp_id;
	int	cy_id;
	int	pl_id;
	int	po_id;
	int	light_id;
}	t_id;

float	parse_str_to_float(char *str);
t_color	parse_color(char *line);
t_vec	parse_coords(char *line);
void	parse_obj_datas(t_minirt *rt, int fd);
void	alloc_objects_arrays(t_minirt *rt);

void	parse_light(t_minirt *rt, char *line, int obj_id);
void	parse_ambient(t_minirt *rt, char *line);
void	parse_camera(t_minirt *rt, char *line);
void	parse_plane(t_minirt *rt, char *line, int obj_id);
void	parse_cylinder(t_minirt *rt, char *line, int obj_id);
void	parse_sphere(t_minirt *rt, char *line, int obj_id);
void	parse_polygon(t_minirt *rt, char *line, int obj_id);

#endif