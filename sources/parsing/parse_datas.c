/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_datas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:38:03 by enoye             #+#    #+#             */
/*   Updated: 2022/07/14 12:29:56 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../headers/minirt.h"

int	parse_datas(t_minirt *rt, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	parse_objects_num(rt, fd);
	close (fd);
	parse_alloc_obj_arr(rt);
	parse_obj_id(rt);
	fd = open(filename, O_RDONLY);
	parse_obj_datas(rt, fd);
}