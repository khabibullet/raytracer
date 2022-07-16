/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:30:53 by enoye             #+#    #+#             */
/*   Updated: 2022/07/04 10:55:52 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../libraries/libft/libft.h"

int	is_right_light(char *line)
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
	if (is_right_ratio(line) == 0)
		return (0);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
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