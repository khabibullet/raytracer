/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:12:07 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/21 16:04:13 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	main(void)
{
	// void	*mlx;
	// void	*win;
	// float	a;

	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 1000, 1000, "here");
	// (void)win;
	// // mlx_loop(mlx);
	// a = -10;
	// printf("%d\n", isnan(sqrtf(a)));
	t_pix	kek;
	float density, ratio;
	int	i = 0, j = 0, h = 100, w = 150;

	density = 1 /  (float) w;
	ratio = (float) h / (float) w;

	kek = find_pix_coords(i, j, density, ratio);
	printf("x:%f!   y:%f!\n", kek.x, kek.y);
	return (0);
}
