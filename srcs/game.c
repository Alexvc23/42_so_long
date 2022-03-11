/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:01:37 by jvalenci          #+#    #+#             */
/*   Updated: 2022/03/11 12:36:24 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

/* it fetches up 'P' coordinates */
void	ft_get_p(t_vars *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->colums)
		{
			if ((map->map[i][j] == 'P'))
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
	char up = map->map[map->y_p - 1][map->x_p];
	char down = map->map[map->y_p + 1][map->x_p];
	char right = map->map[map->y_p][map->x_p + 1];
	char left = map->map[map->y_p][map->x_p - 1];

	if (action == 'U' && up == 'E' && map->n_collectables == 0)
		ft_close_window(map);
	else if (action == 'D' && down == 'E' && map->n_collectables == 0)
		ft_close_window(map);
	else if (action == 'R' && right == 'E' && map->n_collectables == 0)
		ft_close_window(map);
	else if (action == 'L' && left == 'E' && map->n_collectables == 0)
		ft_close_window(map);
	if (action == 'U' && up == 'E' && map->n_collectables > 0)
		ft_print_error(7);
	else if (action == 'D' && down == 'E' && map->n_collectables > 0)
		ft_print_error(7);
	else if (action == 'R' && right == 'E' && map->n_collectables > 0)
		ft_print_error(7);
	else if (action == 'L' && left == 'E' && map->n_collectables > 0)
		ft_print_error(7);
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
	map->mouv++;
	ft_check_char(map);
	ft_check_exit(map, action);
}

/*	Execute the player movements and refresh 'P' coordinates */
void	ft_move_p(t_vars *map, int key)
{
	if ((key == K_W) || (key == K_UP))
	{
		ft_get_p(map);
		if (map->map[map->y_p - 1][map->x_p] != '1')
			ft_exe_move(map, 'U');
	}
	else if (key == K_S || key == K_DOWN)
	{
		ft_get_p(map);
		if (map->map[map->y_p + 1][map->x_p] != '1')
			ft_exe_move(map, 'D');
	}
	else if (key == K_D || key == K_RIGHT)
	{
		ft_get_p(map);
		if (map->map[map->y_p][map->x_p + 1] != '1')
			ft_exe_move(map, 'R');
	}
	else if (key == K_A || key == K_LEFT)
	{
		ft_get_p(map);
		if (map->map[map->y_p][map->x_p - 1] != '1')
			ft_exe_move(map, 'L');
	}
}

/*	Handles all possible movements taking into account events, 
	and quit the programme if needed */
int ft_events(int key, t_vars *vars)
{
    vars->n_players = 0;
    vars->n_collectables = 0;
    vars->n_exits = 0;
	if (key == K_W || key == K_A || key == K_S || key == K_D || key == K_UP \
	|| key == K_DOWN || key == K_LEFT || key == K_RIGHT)
	{
		ft_move_p(vars, key);
		printf("movements: %d\n", vars->mouv);
	}
	if (key == K_ESC)
		ft_close_window(vars);
	ft_push_img(vars);
	return (0);
}