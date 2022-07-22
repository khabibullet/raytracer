/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:58:31 by enoye             #+#    #+#             */
/*   Updated: 2022/07/22 22:08:30 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../libraries/libft/libft.h"

static char	move_line(char *line)
{
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	return (line);
}

int	valid_cylinder(char *line)
{
	if (is_right_coord(line) == 0)
		return (0);
	line = move_line(line);
	if (is_right_norm_vec(line) == 0)
		return (0);
	line = move_line(line);
	if (is_right_float(line) == 0)
		return (0);
	line = move_line(line);
	if (is_right_float(line) == 0)
		return (0);
	line = move_line(line);
	if (is_right_rgb(line) == 0)
		return (0);
	while (*line != ' ' && *line != '\n' && *line != '\0')
		line++;
	while (*line == ' ')
		line++;
	if (*line != '\n' && *line != '\0')
		return (0);
	return (1);
}
