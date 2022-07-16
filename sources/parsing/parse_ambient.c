/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:44:37 by enoye             #+#    #+#             */
/*   Updated: 2022/07/14 12:30:04 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../headers/minirt.h"

void	parse_ambient(t_minirt *rt, char *line)
{
	char	*start;

	line++;
	while (*line == ' ')
		line++;
	start = line;
	while (*line != ' ')
		line++;
	*line = '\0';
	rt->scene.ambient.ratio = parse_str_to_float(start);
	*line = ' ';
	while (*line == ' ')
		line++;
	rt->scene.ambient.color = parse_color(line);
}