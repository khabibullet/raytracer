/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_norm_vec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 12:09:30 by enoye             #+#    #+#             */
/*   Updated: 2022/07/02 16:14:25 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

int	is_right_norm_vec(char *line)
{
	int	k;

	k = 0;
	while (k < 3)
	{
		if (*line != '0' && *line != '1')
			return (0);
		if (*line == '1')
		{
			if (*(line + 1) == '.' && *(line + 2) == '0')
				line = line + 3;
			else if (k != 2 && *(line + 1) == ',')
				line = line + 2;
			else if (k == 2 && *(line + 1) == ' ')
				line++;
			else
				return (0);
		}
		else if (*line == '0')
		{
			while (*line == '0')
				line++;
			if (*line != '.')
				return (0);
			else
				line++;
			if (is_digit(*line) == 0)
				return (0);
			while (is_digit(*line) == 1)
				line++;
			if (k != 2 && *line != ',')
				return (0);
			if (k == 2 && *line != ' ')
				return (0);
		}
		k++;
	}
}