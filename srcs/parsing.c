/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:53:54 by jvalenci          #+#    #+#             */
/*   Updated: 2022/03/25 11:34:27 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

/* count # of lines in the map */
int	ft_count_lines(t_vars *map, char **argv)
{
	map->fd = open(argv[1], O_RDWR, S_IRUSR);
	if (map->fd < 0)
		return (-1);
	while (1)
	{
		map->temp = get_next_line(map->fd);
		if (map->temp == NULL)
			break ;
		map->lines++;
		free(map->temp);
	}
	close(map->fd);
	return (0);
}

/* free two dimentional array storing map */
void	ft_free_map(t_vars *map)
{
	int	i;

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
   information later on */

int	ft_parce_map(t_vars *map, char **argv)
{
	map->i = 0;
	map->lines = 0;
	if (ft_count_lines(map, argv) < 0)
		return (-1);
	map->map = malloc(map->lines * sizeof(char *));
	if (!map->map)
		return (-1);
	map->fd = open(argv[1], O_RDWR, S_IRUSR);
	if (map->fd < 0)
		return (-1);
	while (1)
	{
		map->temp = get_next_line(map->fd);
		if (map->temp == NULL)
			break ;
		map->map[map->i++] = map->temp;
	}
	close(map->fd);
	map->colums = ft_strlen(map->map[0]);
	if (ft_check_errors(map))
		return (-1);
	return (0);
}
