/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:01:40 by enoye             #+#    #+#             */
/*   Updated: 2022/09/14 23:06:03 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../headers/minirt.h"

void	parse_sphere(char *line, t_scene *scene, int type)
{
	static int	num;
	char		**params;

	params = ft_split(line, ' ');
	parse_coords(params[0], &scene->spheres[num].center);
	if (type == SPHERE)
	{
		scene->spheres[num].radius = ft_atof(params[1]) / 2.0F;
		scene->spheres[num].type = SPHERE;
	}
	else
	{
		scene->spheres[num].radius = 1;
		scene->spheres[num].type = BULB;
	}
	parse_rgb_object(params[2], &scene->spheres[num].color);
	free(params[0]);
	free(params[1]);
	free(params[2]);
	free(params);
	num++;
}
