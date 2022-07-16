/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:27:27 by enoye             #+#    #+#             */
/*   Updated: 2022/07/16 15:56:25 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../headers/minirt.h"

void	parse_cylinder(t_minirt *rt, char *line, int obj_id)
{
	char	*start;

	line = line + 2;
	while (*line == ' ')
		line++;
	rt->scene.cylinders[obj_id].axis = parse_coords(line);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	rt->scene.cylinders[obj_id].center = parse_coords(line);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	start = line;
	while (*line != ' ')
		line++;
	*line = '\0';
	rt->scene.cylinders[obj_id].radius = parse_str_to_float(line);
	*line = ' ';
	while (*line == ' ')
		line++;
	start = line;
	while (*line != ' ')
		line++;
	*line = '\0';
	rt->scene.cylinders[obj_id].height = parse_str_to_float(line);
	*line = ' ';
	while (*line == ' ')
		line++;
	rt->scene.cylinders[obj_id].color = parse_color(line);
}