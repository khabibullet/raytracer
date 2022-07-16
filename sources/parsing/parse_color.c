/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:09:34 by enoye             #+#    #+#             */
/*   Updated: 2022/07/14 15:00:22 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../headers/color.h"

t_color	parse_color(char *line)
{
	t_color	var;
	char	*start;
	char	tmp;

	start = line;
	while (*line != ',')
		line++;
	*line = '\0'
	var.r = parse_str_to_float(start) / 255;
	*line = ',';
	line++;
	start = line;
	while (*line != ',')
		line++;
	*line = '\0'
	var.g = parse_str_to_float(start) / 255;
	*line = ',';
	line++;
	start = line;
	while (*line != ' ' && *line != '\n' && *line != '\0')
		line++;
	tmp = *line;
	*line = '\0'
	var.b = parse_str_to_float(start) / 255;
	*line = tmp;
	return (var);
}