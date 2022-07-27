/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:29:16 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/27 18:43:48 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include <unistd.h>
# include <stdlib.h>

# include "scene.h"
# include "utils.h"

# include "../libraries/libft/libft.h"

typedef struct s_elements
{
	int	ambient;
	int	camera;
}	t_elements;

void	validate_config(int argc, char *filename, t_num *num_of);
void	valid_camera(char *line);
void	valid_ambient(char *line);
int		valid_sphere(char *line);
int		valid_cylinder(char *line);
int		valid_light(char *line);
int		valid_plane(char *lane);
int		valid_polygon(char *line);
void	check_rgb(char *line);
void	check_ratio(char *line);
void	check_num_of_fields(char **split, int num);
void	check_num_of_char(char *str, char ch, int num);
void	check_digit_or_charset(char *str, char *charset);
void	check_coords(char *coords);
void	check_normal_vect(char *line);
int		count_char(char *str, char ch);

#endif