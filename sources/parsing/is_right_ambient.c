/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:08:09 by enoye             #+#    #+#             */
/*   Updated: 2022/07/05 16:25:02 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

int	is_right_ambient(char *line)
{
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