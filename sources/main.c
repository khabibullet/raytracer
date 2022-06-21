/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:12:07 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/21 12:49:20 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	float	a;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "here");
	(void)win;
	// mlx_loop(mlx);
	a = -10;
	printf("%d\n", isnan(sqrtf(a)));
	return (0);
}
