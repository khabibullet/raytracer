/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:31:17 by enoye             #+#    #+#             */
/*   Updated: 2022/07/14 12:31:17 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../headers/minirt.h"

void	parse_light(t_minirt *rt, char *line, int obj_id)
{
	char	*start;

	line++;
	rt->scene.lights[obj_id].coords = parse_coords(line);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	start = line;
	while (*line != ' ')
		line++;
	*line = '\0';
	rt->scene.lights[obj_id].brightless = parse_str_to_float(start);
	*line = ' ';
	while (*line == ' ')
		line++;
	rt->scene.lights[obj_id].color = parse_color(line);
}