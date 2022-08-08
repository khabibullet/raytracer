/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:05:07 by anemesis          #+#    #+#             */
/*   Updated: 2022/08/08 14:31:20 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"
#include "../../headers/utils.h"
#include "../../libraries/libft/libft.h"

inline void	put_fps(void *mlx_ptr, void *mlx_win, t_fps *fps)
{
	static long int		prev_time;
	static int			count;
	int					num;
	char				*fps_val;

	if (count == 0)
		prev_time = current_time_ms();
	if (count == 20)
	{
		num = 20000 / (float)(current_time_ms() - prev_time);
		if (num > 999)
			num = 999;
		fps_val = ft_itoa(num);
		ft_strlcpy(&fps->str[4], fps_val, ft_strlen(fps_val) + 1);
		free(fps_val);
	}
	mlx_string_put(mlx_ptr, mlx_win, fps->x_pos, fps->y_pos, \
														fps->color, fps->str);
	count++;
	if (count == 21)
		count = 0;
}
