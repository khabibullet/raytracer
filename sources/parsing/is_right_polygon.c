/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_polygon.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:13:08 by enoye             #+#    #+#             */
/*   Updated: 2022/07/07 13:23:53 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../libraries/libft/libft.h"

static char move_line(char *line)
{
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	return (line);
}

int	is_right_polygon(char *line)
{
	line = line + 2;
	while (*line == ' ')
		line++;
	if (is_right_coord(line) == 0)
		return (0);
	line = move_line(line);
	if (is_right_coord(line) == 0)
		return (0);
	line = move_line(line);
	if (is_right_coord(line) == 0)
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