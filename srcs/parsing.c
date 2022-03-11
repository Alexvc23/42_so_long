/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:37:37 by jvalenci          #+#    #+#             */
/*   Updated: 2022/03/11 11:49:42 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

/* free two dimentional array storing map */
void    ft_free_map(t_vars *map)
{
    int i;

    i = 0;
    while (i < map->lines)
    {
        free(map->map[i]);
        i++;
    }
    free(map->map);
}

/* Using GNL we fetch each line of the map, storing it in a two dimentional
array. Additionally we count # of lines and colums in order to use this
information later on*/

int    ft_parce_map(t_vars *map)
{
    map->fd = open(MAP, O_RDWR, S_IRUSR);
    if (map->fd < 0)
        return (0);
    map->i = 0;
    map->lines = 0;
    while ((map->temp = get_next_line(map->fd)))
    {
        map->lines++;
        free(map->temp);
    }
    close(map->fd);
    map->map = malloc(map->lines * sizeof(char *));
    map->fd = open(MAP, O_RDWR, S_IRUSR);
    while ((map->temp = get_next_line(map->fd)))
            map->map[map->i++] = map->temp;
    map->colums = ft_strlen(map->map[0]);
    if(ft_check_errors(map))
        return (0);
    return (1);
}