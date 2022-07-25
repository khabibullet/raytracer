/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_datas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:38:03 by enoye             #+#    #+#             */
/*   Updated: 2022/07/24 17:56:46 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "../../headers/parsing.h"
#include "../../headers/minirt.h"

void	parse_datas(t_minirt *rt, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	// parse_objects_num(rt, fd);
	close(fd);
	alloc_objects_arrays(rt);
	// parse_obj_id(rt);
	fd = open(filename, O_RDONLY);
	parse_obj_datas(rt, fd);
}
