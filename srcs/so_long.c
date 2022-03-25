/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:54:03 by jvalenci          #+#    #+#             */
/*   Updated: 2022/03/25 11:36:41 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

/* clear up and destroy current window */
int	ft_close_window(t_vars *mlx, int winner)
{
	int	i;

	i = 0;
	ft_free_map(mlx);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	while (i < 5)
	{
		mlx_destroy_image(mlx->mlx, mlx->map_pieces[i]);
		mlx->map_pieces[i] = NULL;
		i++;
	}
	mlx->mlx = NULL;
	mlx->win = NULL;
	if (winner == 1)
		ft_putstr_fd("You have won\n", 1);
	exit(mlx->loop);
	return (1);
}

/*  set up all the needed pointers, mlx API, pointers to images,
	and windows creation */
void	ft_set_window(t_vars *mlx)
{
	int	i;

	i = 0;
	mlx->mlx = mlx_init();
	mlx->paths[0] = FLOOR;
	mlx->paths[1] = WALL;
	mlx->paths[2] = COLLECTABLE;
	mlx->paths[3] = EXIT;
	mlx->paths[4] = PLAYER;
	mlx->win = mlx_new_window(mlx->mlx, (mlx->colums * 32), \
			(mlx->lines * 32), "so_long");
	while (i < 5)
	{
		mlx->map_pieces[i] = mlx_xpm_file_to_image(mlx->mlx, mlx->paths[i], \
				&mlx->img_width[i], &mlx->img_height[i]);
		i++;
	}
}

/*  fetch up the index representing the pointer containing
	the map tile that we need, this function will be used 
	later on in ft_push_img function */
int	ft_get_index(char *map_set, char letter)
{
	int	counter;
	int	i;
	int	len;

	counter = 0;
	i = 0;
	len = ft_strlen(map_set);
	while (i < len)
	{
		if (letter == map_set[i])
			return (counter);
		i++;
		counter++;
	}
	return (-1);
}

/*  Reads each character in the map and prints the corresponding
	image */
void	ft_push_img(t_vars *mlx)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	while (i < mlx->lines)
	{
		j = 0;
		while (j < mlx->colums)
		{
			index = ft_get_index(MAP_CHARS, mlx->map[i][j]);
			if (index < 0)
				return ;
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map_pieces[index], \
					(j * 32), (i * 32));
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	(void)argv;

	vars.mouv = 0;
	if (argc != 2)
		return (write(2, "Wrong number of arguments\n", 27));
	if (ft_parce_map(&vars, argv) < 0)
		return (write(2, "Error parsing the map\n", 23));
	ft_set_window(&vars);
	ft_push_img(&vars);
	mlx_hook(vars.win, 2, 1L << 0, ft_events, &vars);
	mlx_hook(vars.win, 17, 0, ft_close_window, &vars);
	vars.loop = mlx_loop(vars.mlx);
}
