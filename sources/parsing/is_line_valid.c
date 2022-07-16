/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_line_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:41:48 by enoye             #+#    #+#             */
/*   Updated: 2022/07/07 12:29:10 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

int	is_line_valid(char *line)
{
	int	what;

	what = 0;
	while (*line == ' ')
		line++;
	if (*line == '\n')
		return (1);
	if (*line == 'A' && *(line + 1) == ' ')
		what = is_right_ambient(line);
	else if (*line == 'C' && *(line + 1) == ' ')
		what = is_right_camera(line);
	else if (*line == 'L' && *(line + 1) == ' ')
		what = is_right_light(line);
	else if (*line == 's' && *(line + 1) == 'p' && *(line + 2) == ' ')
		what = is_right_sphere(line);
	else if (*line == 'p' && *(line + 1) == 'l' && *(line + 2) == ' ')
		what = is_right_plane(line);
	else if (*line == 'c' && *(line + 1) == 'y' && *(line + 2) == ' ')
		what = is_right_cylinder(line);
	else if (*line == 'p' && *(line + 1) == 'o' && *(line + 2) == ' ')
		what = is_right_polygon(line);
	else
		return (0);
	return (what);
}