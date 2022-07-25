/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_polygon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:23:35 by enoye             #+#    #+#             */
/*   Updated: 2022/07/24 17:59:22 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../headers/minirt.h"

void	parse_polygon(t_minirt *rt, char *line, int obj_id)
{
	line = line + 2;
	while (*line == ' ')
		line++;
	rt->scene.polygons[obj_id].peak1 = parse_coords(line);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	rt->scene.polygons[obj_id].peak2 = parse_coords(line);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	rt->scene.polygons[obj_id].peak3 = parse_coords(line);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	rt->scene.polygons[obj_id].color = parse_color(line);
}
