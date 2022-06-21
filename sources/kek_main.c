/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:27:00 by enoye             #+#    #+#             */
/*   Updated: 2022/06/21 22:24:33 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	main(void)
{
	// void	*mlx;
	// void	*win;

	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 1000, 1000, "here");
	// (void)win;
	// // mlx_loop(mlx);

	t_cam	cam_dir;
	float	focal;
	t_ray	ray;
	t_pix	pix;
	float	ratio, density;
	t_vec	tmp;
	t_sphere;

	cam.coords = (t_vec) {0, 0, 0};
	cam.direction = (t_vec) {1, 0, 0};
	cam.fov = 60;
	focal = 1.73;
	int i = 0;
	density = 0.001;
	ratio = 1;

	while (i < 999)
	{
		j = 0;
		while (j < 999)
		{
			pix = find_pix_coords(i, j, density, ratio);
			ray.coords = get_cam_to_pix_vec(cam.direction, focal, pix);
			ray.origin = get_cam_to_pix_vec(cam.direction, focal, pix);
			tmp = encouter_sphere(ray, spehere);
			if (is_non(tmp.x) != FP_NON)
				mlx_pixel_put(mlx, win, i, j, 0x000000000);
			j++;
		}
		i++;
	}

	return (0);
}
