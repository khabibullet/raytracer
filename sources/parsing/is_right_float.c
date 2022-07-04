/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:27:51 by enoye             #+#    #+#             */
/*   Updated: 2022/07/04 10:43:53 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../libraries/libft/libft.h"

int	is_right_float(char *line)
{
	if (ft_isdigit(*line) == 0)
		return (0);
	while (ft_isdigit(*line) == 1)
		line++;
	if (*line != ' ' && *line != '.')
		return (0);
	if (*line == ' ')
		return (1);
	else if (*line == '.')
	{
		line++;
		if (ft_isdigit(*line) == 0)
			return (0);
		while (ft_isdigit(*line) == 1)
			line++;
		if (*line == ' ')
			return (1);
	}
	return (0);
}