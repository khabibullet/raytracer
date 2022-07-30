/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:27:27 by enoye             #+#    #+#             */
/*   Updated: 2022/07/30 19:08:29 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../headers/minirt.h"

void	parse_cylinder(char *line, t_scene *scene)
{
	static int	cyl_num;
	char		**params;

	params = ft_split(line, ' ');
	parse_coords(params[0], &scene->cylinders[cyl_num].center);
	parse_coords(params[1], &scene->cylinders[cyl_num].axis);
	scene->cylinders[cyl_num].radius = ft_atof(params[2]) / 2.0F;
	scene->cylinders[cyl_num].semi_heigth = ft_atof(params[3]);
	parse_rgb_object(params[4], &scene->cylinders[cyl_num].color);
	free(params[0]);
	free(params[1]);
	free(params[2]);
	free(params[3]);
	free(params[4]);
	free(params);
	cyl_num++;
}
