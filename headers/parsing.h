/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:58:36 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/16 15:11:18 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"
# include <stdio.h>

typedef struct	s_id
{
	int	sp_id;
	int	cy_id;
	int	pl_id;
	int	po_id;
	int	light_id;
}	t_id;

typedef struct s_elements
{
	int	ambient;
	int	light;
	int	camera;
	int	object;
}	t_elements;

void	parse_rt(int argc, char **argv, t_minirt *rt);
void	init_window_and_buffers(t_minirt *rt);
void	init_rays(t_minirt *rt);
void	alloc_objects_arrays(t_minirt *rt);
void	alloc_tmp_collisions_array(t_minirt *rt);



int		is_all_valid(int fd, char *name);
int		is_right_norm_vec(char *line);
int		is_right_coord(char *line);
int		is_right_camera(char *line);
int		is_right_ambient(char *line);
int		is_line_valid(char *line);
int		is_right_sphere(char *line);
int		is_right_cylinder(char *line);
int		is_right_light(char *line);
int		is_right_plane(char *lane);
int		is_right_rgb(char *line);
int		is_right_float(char *line);
int		is_right_ratio(char *line);
int		is_file_valid(char *name);

#endif