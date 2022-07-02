/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_line_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:41:48 by enoye             #+#    #+#             */
/*   Updated: 2022/07/02 16:20:57 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

int	is_line_valid(char *line)
{
	while (*line == ' ')
		line++;
	if (*line == '\n')
		return (1);
	if (*line == 'A' && *(line + 1) == ' ')
	{
		if (is_right_ambient(line) == 0)
			return (0);
	}
	else if (*line == 'C' && *(line + 1) == ' ')
	{
		if (is_right_camera(line) == 0)
			return (0);
	}
	else if (*line == 'L' && *(line + 1) == ' ')
	{
		if (is_right_light(line) == 0)
			return (0);
	}
	return (1);
}