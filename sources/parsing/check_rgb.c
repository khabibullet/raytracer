/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:00:45 by enoye             #+#    #+#             */
/*   Updated: 2022/07/02 16:12:09 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

static	int	final_check_rgb(char *line)
{
	if (*(line - 3) > '2')
		return (0);
	else if (*(line - 3) == '2' && *(line - 2) > '5')
		return (0);
	else if (*(line - 3) == '2' && *(line - 2) == '5' && *(line - 1) > '5')
		return (0);
	return (1);
}

int	check_rgb(char *line)
{
	int		i;

	while (*line != '\0' || *line != ' ' || *line != '\n')
	{
		i = 0;
		if (is_digit(*line) == 0)
			return (0);
		while (is_digit(*line) == 1)
		{
			i++;
			line++;
		}
		if (i > 3)
			return (0);
		if (*line != ',')
			return (0);
		if (i == 3)
		{
			if (final_check_rgb(line) == 0)
				return (0);
		}
		line++;
	}
	while (*line == ' ')
		line++;
	if (*line != '\0' && *line != '\n')
		return (0);
	return (1);
}