/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:30:57 by enoye             #+#    #+#             */
/*   Updated: 2022/07/12 13:26:15 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	continue_pars_obj_id(t_minirt *rt)
{
	int i;

	i = 0;
	while (i < rt->scene.num_of.cylinders)
	{
		rt->scene.cylinders[i].id = i;
		i++;
	}
	i = 0;
	while (i < rt->scene.num_of.lights)
	{
		rt->scene.lights[i].id = i;
		i++;
	}
}

void	parse_obj_id(t_minirt *rt)
{
	int i;

	i = 0;
	while (i < rt->scene.num_of.polygones)
	{
		rt->scene.polygones[i].id = i;
		i++;
	}
	i = 0;
	while (i < rt.scene.num_of.spheres)
	{
		rt->scene.spheres[i].id = i;
		i++;
	}
	i = 0;
	while (i < rt.scene.num_of.planes)
	{
		rt->scene.planes[i].id = i;
		i++;
	}
	continue_pars_obj_id(rt);
}