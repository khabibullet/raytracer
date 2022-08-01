/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_raytracing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:10:44 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/01 23:57:00 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/event.h"
#include "../../headers/utils.h"

int	phong_raytracing(t_minirt *rt)
{
	emit_rays(rt);
	get_nearest_collisions(rt); // получение координат и типа объекта ближайшего к камере пересечения
	get_ambient_component(rt); // добавление в цвет луча амбиентной компоненты
	put_colors_to_back_buff(rt); // перенос цвета лучей в задний буфер
	put_buffer_to_window(rt, &rt->phong_buffer);
	update_rays(rt); // замена полей начала луча, направления луча и нормали к поверхности
	get_diffuse_component(rt); // добавление диффузной компоненты к цвету лучей
	put_colors_to_back_buff(rt); // перевод
	put_buffer_to_window(rt, &rt->phong_buffer);
	get_specular_component(rt); // добавление амбиентной компоненты к цвету лучей
	put_colors_to_back_buff(rt); // перевод
	put_buffer_to_window(rt, &rt->phong_buffer);
	return (0);
}
