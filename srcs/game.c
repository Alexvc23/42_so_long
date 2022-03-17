/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:18:25 by jvalenci          #+#    #+#             */
/*   Updated: 2022/03/17 13:18:36 by jvalenci         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

/* it fetches up 'P' coordinates */
void	ft_get_p(t_vars *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->colums)
		{
			if (map->map[i][j] == 'P')
			{
				map->y_p = i;
				map->x_p = j;
				return ;
			}
			j++;
		}
		i++;
	}
	map->y_p = 0;
	map->x_p = 0;
}

/*	Checks that our player cannot quit the game up until all the 
	collectables are gathered */
void	ft_check_exit(t_vars *map, char action)
{
	char	up;
	char	down;
	char	right;
	char	left;

	up = map->map[map->y_p - 1][map->x_p];
	down = map->map[map->y_p + 1][map->x_p];
	right = map->map[map->y_p][map->x_p + 1];
	left = map->map[map->y_p][map->x_p - 1];
	if ((action == 'U' && up == 'E' && map->n_collectables == 0) || \
			(action == 'D' && down == 'E' && map->n_collectables == 0) || \
			(action == 'R' && right == 'E' && map->n_collectables == 0) || \
			(action == 'L' && left == 'E' && map->n_collectables == 0))
		ft_close_window(map, 1);
	if ((action == 'U' && up == 'E' && map->n_collectables > 0) || \
			(action == 'D' && down == 'E' && map->n_collectables > 0) || \
			(action == 'R' && right == 'E' && map->n_collectables > 0) || \
			(action == 'L' && left == 'E' && map->n_collectables > 0))
		ft_print_error(7);
	if ((up != 'E') && (down != 'E') && (right != 'E') && (left != 'E'))
		map->mouv++;
}

/*	Execute the player movements along with the function ft_move_p
	located below */
void	ft_exe_move(t_vars *map, char action)
{
	if (action == 'U' && map->map[map->y_p - 1][map->x_p] != 'E')
	{
		map->map[map->y_p - 1][map->x_p] = 'P';
		map->map[map->y_p][map->x_p] = '0';
	}
	else if (action == 'D' && map->map[map->y_p + 1][map->x_p] != 'E')
	{
		map->map[map->y_p + 1][map->x_p] = 'P';
		map->map[map->y_p][map->x_p] = '0';
	}
	else if (action == 'R' && map->map[map->y_p][map->x_p + 1] != 'E')
	{
		map->map[map->y_p][map->x_p + 1] = 'P';
		map->map[map->y_p][map->x_p] = '0';
	}
	else if (action == 'L' && map->map[map->y_p][map->x_p - 1] != 'E')
	{
		map->map[map->y_p][map->x_p - 1] = 'P';
		map->map[map->y_p][map->x_p] = '0';
	}
	ft_check_char(map);
	ft_check_exit(map, action);
}

/*	Execute the player movements and refresh 'P' coordinates */
void	ft_move_p(t_vars *map, int key)
{
	ft_get_p(map);
	if ((key == K_W) || (key == K_UP))
	{
		if (map->map[map->y_p - 1][map->x_p] != '1')
			ft_exe_move(map, 'U');
	}
	else if (key == K_S || key == K_DOWN)
	{
		if (map->map[map->y_p + 1][map->x_p] != '1')
			ft_exe_move(map, 'D');
	}
	else if (key == K_D || key == K_RIGHT)
	{
		if (map->map[map->y_p][map->x_p + 1] != '1')
			ft_exe_move(map, 'R');
	}
	else if (key == K_A || key == K_LEFT)
	{
		if (map->map[map->y_p][map->x_p - 1] != '1')
			ft_exe_move(map, 'L');
	}
}

/*	Handles all possible movements taking into account events, 
	and quit the programme if needed */
int	ft_events(int key, t_vars *vars)
{
	vars->n_players = 0;
	vars->n_collectables = 0;
	vars->n_exits = 0;
	ft_putnbr_fd(key, 1);
	ft_putstr_fd("\n", 1);
	if (key == K_W || key == K_A || key == K_S || key == K_D || key == K_UP \
			|| key == K_DOWN || key == K_LEFT || key == K_RIGHT)
	{
		ft_move_p(vars, key);
		ft_putstr_fd("movements: ", 1);
		ft_putnbr_fd(vars->mouv, 1);
		ft_putstr_fd("\n", 1);
	}
	if (key == K_ESC)
		ft_close_window(vars, 0);
	ft_push_img(vars);
	return (0);
}
