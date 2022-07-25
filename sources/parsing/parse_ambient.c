/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:44:37 by enoye             #+#    #+#             */
/*   Updated: 2022/07/24 17:35:06 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../headers/minirt.h"

void	parse_ambient(t_minirt *rt, char *line)
{
	char	*start;

	(void)rt;
	line++;
	while (*line == ' ')
		line++;
	start = line;
	(void)start;
	while (*line != ' ')
		line++;
	*line = '\0';
	// rt->scene.ambient.ratio = parse_str_to_float(start);
	// *line = ' ';
	// while (*line == ' ')
	// 	line++;
	// rt->scene.ambient.color = parse_color(line);
}
