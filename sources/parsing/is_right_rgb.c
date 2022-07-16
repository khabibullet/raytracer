/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:00:45 by enoye             #+#    #+#             */
/*   Updated: 2022/07/05 13:07:50 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../libraries/libft/libft.h"

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

static int	check_end(char *line, int i, int k)
{
	if (i > 3)
		return (0);
	if (i == 3 && final_check_rgb(line) == 0)
		return (0);
	if (k == 2 && (*line == ' ' || *line == '\n' || *line == '\0'))
		return (1);
	else if (k != 2 && *line != ',')
		return (0);
	return (10);
}

int	is_right_rgb(char *line)
{
	int	k;
	int	i;

	k = 0;
	while (k < 3)
	{
		if (ft_isdigit(*line) == 0)
			return (0);
		while (*line == '0')
				line++;
		i = 0;
		while (ft_isdigit(*line) == 1)
		{
			line++;
			i++;
		}
		i = check_end(line, i, k);
		if (i == 0)
			return (0);
		else if (i == 1)
			return (1);
		line++;
		k++;
	}
	return (1);
}