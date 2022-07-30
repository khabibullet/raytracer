/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:29:16 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/30 19:01:11 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include <unistd.h>
# include <stdlib.h>

# include "minirt.h"
# include "utils.h"

# include "../libraries/libft/libft.h"

void	validate_config(int argc, char *filename, t_num *num_of);
void	valid_camera(char *line);
void	valid_ambient(char *line);
void	valid_sphere(char *line);
void	valid_cylinder(char *line);
void	valid_light(char *line);
void	valid_plane(char *lane);
void	valid_polygon(char *line);
void	check_rgb(char *line);
void	check_ratio(char *line);
void	check_num_of_fields(char **split, int num);
void	check_num_of_char(char *str, char ch, int num);
void	check_digit_or_charset(char *str, char *charset);
void	check_coords(char *coords);
void	check_normal_vect(char *line);
int		count_char(char *str, char ch);

#endif