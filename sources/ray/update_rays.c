/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:27:25 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/05 14:37:11 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ray->coords = vec_multiply_nbr(ray->coords, ray->collis.distance - EPSILON);
curr_ray->origin = add_vecs(curr_ray->origin, curr_ray->coords);
curr_ray->coords = vec_multiply_nbr(curr_ray->coords, -1.0F);
curr_ray->surface = collision.surface;
get_surf_normal();