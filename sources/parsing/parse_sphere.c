/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:01:40 by enoye             #+#    #+#             */
/*   Updated: 2022/07/24 17:58:35 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../headers/minirt.h"

void	parse_sphere(t_minirt *rt, char *line, int obj_id)
{
	char	*start;

	line = line + 2;
	while (*line == ' ')
		line++;
	rt->scene.spheres[obj_id].center = parse_coords(line);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	start = line;
	while (*line != ' ')
		line++;
	*line = '\0';
	rt->scene.spheres[obj_id].radius = parse_str_to_float(start) / 2;
	*line = ' ';
	while (*line == ' ')
		line++;
	rt->scene.spheres[obj_id].color = parse_color(line);
}
