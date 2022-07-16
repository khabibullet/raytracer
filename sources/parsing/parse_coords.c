/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_coords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:46:03 by enoye             #+#    #+#             */
/*   Updated: 2022/07/14 13:02:04 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../headers/vector.h"

t_vec	parse_coords(char *line)
{
	char	*end;
	t_vec	vector;
	int		x;

	x = 1;
	end = line;
	while (*end != ' ')
	{
		if (*end == ',')
		{
			*end = '\0';
			if (x == 1)
				vector.x = parse_str_to_float(line);
			else
				vector.y = parse_str_to_float(line);
			line = end + 1;
			*end = ',';
			x = 0;
		}
		end++;
	}
	*end = '\0'
	vector.z = parse_str_to_float(line);
	*end = ' ';
	return (vector);
}