/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:29:16 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/23 22:04:35 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "scene.h"

typedef struct s_id
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
	int	camera;
}	t_elements;

void	validate_config(int argc, char *filename, t_num *num_of);
int		valid_camera(char *line);
void	valid_ambient(char *line);
int		valid_sphere(char *line);
int		valid_cylinder(char *line);
int		valid_light(char *line);
int		valid_plane(char *lane);
void	check_rgb(char *line);
void	check_ratio(char *line);

int		is_right_norm_vec(char *line);
int		is_right_coord(char *line);
int		is_right_float(char *line);

#endif