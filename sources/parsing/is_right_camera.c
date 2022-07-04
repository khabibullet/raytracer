/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:18:29 by enoye             #+#    #+#             */
/*   Updated: 2022/07/04 10:56:25 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../libraries/libft/libft.h"

static int	is_right_pov(char *line)
{
	int	k;

	k = 0;
	if (*line == '0')
	{
		while (*line == '0')
			line++;
		if (*line == ' ' || *line == '\n' || *line == '\0')
			return (1);
	}
	if (ft_isdigit(*line) == 0)
		return (0);
	while (ft_isdigit(*line) == 1)
	{
		line++;
		k++;
	}
	if (k > 3)
		return (0);
	if (*line != ' ' && *line != '\n' && *line != '\0')
		return (0);
	if (k == 3)
	{
		if (*(line - 3) > '1')
			return (0);
		if (*(line - 3) == '1' && *(line - 2) > '8')
			return (0);
		if (*(line - 3) == '1' && *(line - 2) == '8' && *(line - 1) > '0')
			return (0);
	}
	return (1);
}

int	is_right_camera(char *line)
{
	line++;
	while (*line == ' ')
		line++;
	if (is_right_coord(line) == 0)
		return (0);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	if (is_right_norm_vec(line) == 0)
		return (0);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	if (is_right_pov(line) == 0)
		return (0);
	while (*line != ' ' && *line != '\n' && *line != '\0')
		line++;
	while (*line == ' ')
		line++;
	if (*line != '\n' && *line != '\0')
		return (0);
	return (1);
}