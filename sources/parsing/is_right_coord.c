/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_coord.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:25:41 by enoye             #+#    #+#             */
/*   Updated: 2022/07/02 16:14:19 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

int	is_right_coord(char *line)
{
	int	k;

	k = 0;
	while (k < 3)
	{
		if (*line == '-')
			line++;
		if (is_digit(*line) == 0)
			return (0);
		while (is_digit(*line) == 1)
			line++;
		if (*line != '.' && *line != ',')
			return (0);
		if (*line == ',' && k != 2)
			line++;
		else if (*line == '.')
		{
			line++;
			if (is_digit(*line) == 0)
				return (0);
			while (is_digit(*line) == 1)
				line++;
			if (*line == ',' && k != 2)
				line++;
		}
		k++;
	}
	if (*line != ' ')
		return (0);
	return (1);
}