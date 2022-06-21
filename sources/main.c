/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:12:07 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/21 17:24:53 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	main(void)
{
	t_list		*objects;
	t_list		*tmp;
	t_cam		camera;
	t_sphere	sphere;

	camera.id = 'C';
	sphere.id = 's';
	tmp = malloc(sizeof(*tmp));
	tmp->prev = NULL;
	tmp->next = NULL;
	tmp->object = &camera;
	objects = tmp;
	tmp = malloc(sizeof(*tmp));
	tmp->prev = objects;
	tmp->next = NULL;
	tmp->object = &sphere;
	tmp = objects;
	if (*(int *)tmp->object == 'C')
		printf("Cam found on position 1!\n");
	else
	{
		tmp = tmp->next;
		if (*(int *)tmp->object == 'C')
			printf("Cam found on position 2!\n");
	}
	return (0);
}
