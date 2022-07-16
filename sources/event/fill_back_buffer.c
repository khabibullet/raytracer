/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_back_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:10:44 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/16 15:14:24 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "../../headers/minirt.h"
#include "../../headers/test.h"
#include "../../headers/utils.h"

int	fill_back_buffer(t_minirt *rt)
{
	emit_rays(rt); // рассчет вектора луча
	get_nearest_collisions(rt); // получение координат и типа объекта ближайшего к камере пересечения
	get_ambient_component(rt); // добавление в цвет луча амбиентной компоненты
	put_colors_to_back_buff(rt); // перенос цвета лучей в задний буфер
	swap_buffers(rt); // вывод заднего буфера на экран
	update_rays(rt); // замена полей начала луча, направления луча и нормали к поверхности
	get_diffuse_component(rt); // добавление диффузной компоненты к цвету лучей
	put_colors_to_back_buff(rt); // перевод
	swap_buffers(rt); // вывод цвета амбиентная + диффузная компоненты
	get_specular_component(rt); // добавление амбиентной компоненты к цвету лучей
	put_colors_to_back_buff(rt); // перевод
	swap_buffers(rt); // вывод всех компонент
	return (0);
}
