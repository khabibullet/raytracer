/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kek_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:27:00 by enoye             #+#    #+#             */
/*   Updated: 2022/06/21 23:15:16 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	main(void)
{
	t_cam		cam;
	float		focal;
	t_ray		ray;
	t_pix		pix;
	float		ratio;
	float		density;
	t_vec		tmp;
	t_sphere	sphere;
	int			j;
	int			i;
	void		*mlx;
	void		*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "here");
	(void)win;

	sphere.center = (t_vec){4, 0, 0};
	sphere.radius = 0.1;
	cam.coords = (t_vec){0, 0, 0};
	cam.direction = (t_vec){1, 0, 0};
	cam.fov = 60;
	focal = 1.73;
	density = 0.001;
	ratio = 1;

	i = 0;
	while (i < 999)
	{
		j = 0;
		while (j < 999)
		{
			pix = find_pix_coords(i, j, density, ratio);
			ray.coords = get_cam_to_pix_vec(cam.direction, focal, pix);
			ray.origin = ray.coords;
			tmp = encounter_sphere(ray, sphere);
			if (isnan(tmp.x) != FP_NAN)
				mlx_pixel_put(mlx, win, i, j, 0x00FFFFFF);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
	return (0);
}
