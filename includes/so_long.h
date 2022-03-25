/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:35:05 by jvalenci          #+#    #+#             */
/*   Updated: 2022/03/25 11:28:59 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#if defined(__linux__)
	#include "sl_keys_linux.h"
#else
	#include "sl_keys.h"
#endif
# define SO_LONG_H
# define MAP_CHARS "01CEP"
# define PLAYER "xpm/player.xpm"
# define FLOOR "xpm/floor.xpm"
# define WALL "xpm/wall.xpm"
# define EXIT "xpm/door.xpm"
# define COLLECTABLE "xpm/collectable.xpm"
# include "mlx.h"
# include "../libft/includes/libft.h"
# include "../gnl/includes/get_next_line.h"

// ── STRUCTS ─────────────────────────────────────────

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	*paths[5];
	int		img_width[5];
	int		img_height[5];
	void	*map_pieces[5];
	int		loop;
	char	**map;
	char	*temp;
	int		fd;
	float	lines;
	float	colums;
	int		i;
	int		n_players;
	int		n_collectables;
	int		n_exits;
	int		x_p;
	int		y_p;
	int		mouv;
}	t_vars;

// ─── FUNCTIONS ─────────────────────────────────────

int		ft_parce_map(t_vars *map, char **argv);
void	ft_free_map(t_vars *map);
int		ft_check_char(t_vars *map);
int		ft_check_errors(t_vars *map);
int		ft_print_error(int error);
int		ft_check_walls(t_vars *map);
int		ft_close_window(t_vars *mlx, int winner);
void	ft_set_window(t_vars *mlx);
void	ft_push_img(t_vars *mlx);
int		ft_events(int key, t_vars *vars);
void	ft_get_p(t_vars *map);

#endif