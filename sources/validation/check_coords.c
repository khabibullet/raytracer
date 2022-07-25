/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:21:44 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/25 19:35:19 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libraries/libft/libft.h"
#include "../../headers/validation.h"

void	check_coords(char *coords)
{
	char	**xyz;

	xyz = ft_split(coords, ',');
	check_num_of_fields(xyz, 3);
	check_float(xyz[0]);
	check_float(xyz[1]);
	check_float(xyz[2]);
}
