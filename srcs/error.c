/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:38:39 by jvalenci          #+#    #+#             */
/*   Updated: 2022/03/11 12:32:50 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Checks for not allowed characters and controls the number of players
   collectables and exits */
int ft_check_char(t_vars *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->lines)
    {
        if (ft_strlen(map->map[i]) != (unsigned int)map->colums)
            return (0);
        j = 0;
        while (j < map->colums)
        {
            if (!ft_strchr(MAP_CHARS, map->map[i][j]))
                return (0);
            if (map->map[i][j] == 'P')
                map->n_players += 1;
            else if (map->map[i][j] == 'C')
                map->n_collectables += 1;
            else if (map->map[i][j] == 'E')
                map->n_exits += 1;
            j++;
        }
        i++;
    }
    return (1);
}

int ft_check_walls(t_vars *map)
{
    int i = 0;
    int j;
    while (i < map->lines)
    {
        j = 0;
        while (j < map->colums)
        {
            if (i == 0 || i == ((int)map->lines - 1))
            {
                if (map->map[i][j] != '1')
                    return (0);
            }
            else if (j == 0 || j == ((int)map->colums - 1))
            {
                if (map->map[i][j] != '1')
                    return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

/* Handles error interface */
int ft_check_errors(t_vars *map)
{
    map->n_players = 0;
    map->n_collectables = 0;
    map->n_exits = 0;
    if ((map->lines / map->colums) > 0.61)
        return (ft_print_error(1));
    else if (!ft_check_char(map))
        return (ft_print_error(2));
    else if (map->n_players != 1)
        return (ft_print_error(3));
    else if (map->n_collectables < 1)
        return (ft_print_error(4));
    else if (map->n_exits < 1)
        return (ft_print_error(5));
    else if (!ft_check_walls(map))
        return (ft_print_error(6));
    return (0);
}

/* Handles error printing */
int ft_print_error(int error)
{
    if (error == 1)
        return (write(1, "The map is nor rectangular\n", 28));
    else if (error == 2)
        return (write(1, "There are forbidden characters in the map\n", 43));
    else if (error == 3)
        return (write(1, "There must be a player in the map\n", 35));
    else if (error == 4)
        return (write(1, "There must be at least one collectable in the\
 map\n",
                      51));
    else if (error == 5)
        return (write(1, "There must be at least one exit in the\
 map\n",
                      43));
    if (error == 6)
        return (write(1, "The map must be sourranded by walls\n", 37));
    if (error == 7)
        return (write(1, "You must gather all collectables before exit the game\n", 55));
    return (0);
}