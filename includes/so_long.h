/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:49:28 by jvalenci          #+#    #+#             */
/*   Updated: 2022/03/11 12:08:24 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#define MAP_CHARS "01CEP"
#define MAP "ber/sub1.ber"
#define PLAYER "xpm/player.xpm"
#define FLOOR "xpm/floor.xpm"
#define WALL "xpm/wall.xpm"
#define EXIT "xpm/door.xpm"
#define COLLECTABLE "xpm/collectable.xpm"
#include "mlx.h"
#include "sl_keys_linux.h"
#include "../libft/includes/libft.h"
#include "../gnl/includes/get_next_line.h"

//
// ── STRUCTS ───────────────────────────────────────────────────────────────────
//
    
typedef struct  s_vars 
{
    void    *mlx;
    void    *win;
    char    *paths[5];
	int     img_width[5];
	int     img_height[5];
    void    *map_pieces[5];
    int     loop;
    char    **map;
    char    *temp;
    int     fd;
    float   lines;
    float   colums;
    int     i;
    int     n_players;
    int     n_collectables;
    int     n_exits;
    int     x_p;
    int     y_p;
    int     mouv;
}               t_vars;

//
// ─── FUNCTIONS ─────────────────────────────────────
//

int     ft_parce_map(t_vars *map);
void    ft_free_map(t_vars *map);
int     ft_check_char(t_vars *map);
int     ft_check_errors(t_vars *map);
int     ft_print_error(int error);
int     ft_check_walls(t_vars *map);
int     ft_close_window(t_vars *mlx);
void    ft_set_window(t_vars *mlx);
void    ft_push_img(t_vars *mlx);
int     ft_events(int key, t_vars *vars);
void	ft_get_p(t_vars *map);

#endif