/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:19:07 by jvalenci          #+#    #+#             */
/*   Updated: 2022/03/03 13:07:50 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int rgb_to_int(int r, int g, int b)
{
	return ((r<<16) + (g<<8) + b);
}
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		x_end = 500;
	int		y_end = 500;
	int		x_start = 0;
	int		y_start = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, x_end, y_end, "Hello world!");
	while (x_start < x_end && y_start < x_end)
	{
		mlx_pixel_put(mlx, mlx_win, x_start, y_start, rgb_to_int(59, 227, 157));
		x_start++;
		y_start++;
	}
	mlx_loop(mlx);
}