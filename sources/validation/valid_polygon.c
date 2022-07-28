/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_polygon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:13:08 by enoye             #+#    #+#             */
/*   Updated: 2022/07/28 13:26:28 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/validation.h"

void	valid_polygon(char *line)
{
	char	**params;

	check_digit_or_charset(line, " .,-");
	check_num_of_char(line, ',', 8);
	params = ft_split(line, ' ');
	check_num_of_fields(params, 4);
	check_coords(params[0]);
	check_coords(params[1]);
	check_coords(params[2]);
	check_rgb(params[3]);
	free(params[0]);
	free(params[1]);
	free(params[2]);
	free(params[3]);
	free(params);
}
