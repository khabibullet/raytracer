/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_buffers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:15:48 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/25 21:02:04 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

void	swap_buffers(t_minirt *rt)
{
	void	*tmp;

	tmp = rt->display_buff.ptr;
	rt->display_buff.ptr = rt->back_buff.ptr;
	rt->back_buff.ptr = tmp;
}
