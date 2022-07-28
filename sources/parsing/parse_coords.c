/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_coords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:46:03 by enoye             #+#    #+#             */
/*   Updated: 2022/07/28 16:53:55 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

void	parse_coords(char *line, t_vec *vec)
{
	char	**xyz;

	xyz = ft_split(line, ',');
	vec->x = ft_atof(xyz[0]);
	vec->y = ft_atof(xyz[1]);
	vec->z = ft_atof(xyz[2]);
	free(xyz[0]);
	free(xyz[1]);
	free(xyz[2]);
	free(xyz);
}
