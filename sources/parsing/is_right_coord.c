/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_coord.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:25:41 by enoye             #+#    #+#             */
/*   Updated: 2022/07/05 16:10:48 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../libraries/libft/libft.h"

static int	if_alone(char **line, int k)
{
	while (ft_isdigit(**line) == 1)
		*line++;
	if (**line == '.')
	{
		*line++;
		if (ft_isdigit(**line) != 1)
			return (0);
		while (ft_isdigit(**line) == 1)
			line++;
		if (k == 2 && **line == ' ') // v konce probel
			return (1);
		else if (k !=2 && **line == ',') // esli ne konec, to zapyataya posle chisla
			*line++;
		else
			return (0);
	}
	else if (k == 2 && **line == ' ')
		return (1);
	else if (k != 2 && **line == ',')
		*line++;
	else
		return (0);
	return (10);
}

int	is_right_coord(char *line)
{
	int	k;
	int res;

	k = 0;
	while (k < 3)
	{
		if (*line == '-')
			line++;
		if (ft_isdigit(*line) == 1)
		{
			res = if_alone(&line, k);
			if (res == 0)
				return (0);
			else if (res == 1)
				return (1);
		}
		else
			return (0);
		k++;
	}
	return (1);
}